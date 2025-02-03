#include <stdatomic.h>
#include <stdbool.h>
#include <sched.h>

// 自旋锁结构
typedef struct {
    atomic_flag flag;
} SpinLock;

// 初始化锁
void spinlock_init(SpinLock *lock) {
    atomic_flag_clear(&lock->flag); // 清除标志，设置为未锁定状态
}

// 加锁
void spinlock_lock(SpinLock *lock) {
    while (atomic_flag_test_and_set(&lock->flag)) {
       // 自旋等待？ 让出来吧宝贝！
       sched_yield(); // 但是上下文切换的成本很大!
          // 多线程场景下，自旋反而表现好?
    }
}

// 解锁
void spinlock_unlock(SpinLock *lock) {
    atomic_flag_clear(&lock->flag);
}

// 测试示例
#include <stdio.h>
#include <pthread.h>

SpinLock lock;
int shared_counter = 0;

void *thread_func(void *arg) {
    for (int i = 0; i < 10000000; i++) {
        spinlock_lock(&lock);
        shared_counter++;
        spinlock_unlock(&lock);
    }
    return NULL;
}

int main() {
    pthread_t threads[10];

    spinlock_init(&lock);

    for (int i = 0; i < 10; i++) {
       pthread_create(&threads[i], NULL, thread_func, NULL);
    }

    for (int i = 0; i < 10; i++) {
       pthread_join(threads[i], NULL);
    }

    printf("Final counter value: %d\n", shared_counter);
    return 0;
}

