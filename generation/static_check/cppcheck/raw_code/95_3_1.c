#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct ThreadJob {
    void (*process)(void*);
    void* arg;
    bool is_done;
    struct ThreadJob* next;
} ThreadJob;

void start_job(ThreadJob* job) {
    while (job != NULL && !job->is_done) {
        job->process(job->arg);
        job->is_done = true; // This line can cause a race condition.
        job = job->next;
    }
}

void add_job(ThreadJob** job_list, void (*function)(void*), void* argument) {
    ThreadJob* new_job = malloc(sizeof(ThreadJob));
    new_job->process = function;
    new_job->arg = argument;
    new_job->is_done = false;
    new_job->next = NULL;

    if (*job_list == NULL) {
        *job_list = new_job;
    } else {
        ThreadJob* last_job = *job_list;
        while (last_job->next) {
            last_job = last_job->next;
        }
        last_job->next = new_job;
    }

    start_job(*job_list); // Should be synchronized but isn't.
}