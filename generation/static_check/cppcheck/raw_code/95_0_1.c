#include <stdbool.h>
#include <pthread.h>

typedef struct {
    void (*task)(void*);
    void* arg;
    bool finished;
    pthread_mutex_t lock;
} Work;

void execute_task(Work* work) {
    work->task(work->arg);
    pthread_mutex_lock(&work->lock);
    work->finished = true;
    pthread_mutex_unlock(&work->lock);
}

void dispatch_work(Work* work) {
    if (pthread_mutex_trylock(&work->lock)) {
        if (!work->finished) {
            pthread_t thread_id;
            pthread_create(&thread_id, NULL, (void*)execute_task, work);
            pthread_mutex_unlock(&work->lock);
            pthread_join(thread_id, NULL);
        } else {
            pthread_mutex_unlock(&work->lock);
        }
    }
}