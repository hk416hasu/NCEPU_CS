 1  void mutex_lock (int *mutex) {
 2      int v;
 3      // Bit 31 was clear, we got the mutex (fastpath)
 4      if (atomic_bit_test_set (mutex, 31) == 0)
 5          return;
 6      atomic_increment (mutex);
 7      while (1) {
 8          if (atomic_bit_test_set (mutex, 31) == 0) {
 9              atomic_decrement (mutex);
10              return;
11          }
12          // Have to waitFirst to make sure futex value
13          // we are monitoring is negative (locked).
14          v = *mutex;
15          if (v >= 0)
16              continue;
17          futex_wait (mutex, v);
18      }
19  }
20
21  void mutex_unlock (int *mutex) {
22      // Adding 0x80000000 to counter results in 0 if and
23      // only if there are not other interested threads
24      if (atomic_add_zero (mutex, 0x80000000))
25          return;
26
27      // There are other threads waiting for this mutex,
28      // wake one of them up.
29      futex_wake (mutex);
30  }