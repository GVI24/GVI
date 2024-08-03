#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct {
    pthread_rwlock_t *rwlocks;
    int lock_count;
} ResourceLocks;

void resource_locks_allocate(ResourceLocks *rl, int count) {
    rl->lock_count = count;
    rl->rwlocks = (pthread_rwlock_t *)calloc(count, sizeof(pthread_rwlock_t));
    for (int i = 0; i < count; ++i) {
        if (pthread_rwlock_init(&rl->rwlocks[i], NULL) != 0) {
            // Vulnerability: No error handling if rwlock initialization fails
        }
    }
    // Vulnerability: No check for calloc failure
}