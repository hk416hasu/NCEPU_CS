typedef struct __lock_t {
    int flag;
} lock_t;

void init (lock_t *lock) {
    // 0: lock is available, 1: lock is held
    lock->flag = 0;
}

void lock (lock_t *lock) {
    while (TestAndSet(&lock->flag, 1) == 1)
        // ;//spin-wait (do nothing)
        yield(); // givp up the cpu
}

void unlock (lock_t *lock) {
    lock->flag = 0;
}
