#include <stdbool.h>
#include <pthread.h>

typedef struct Job {
    void (*execute)(void*);
    void* params;
    struct Job* next;
    volatile bool done;
} Job;

void process_job(Job* job) {
    job->execute(job->params);
    job->done = true;
}

void queue_job(Job** head, void (*work)(void*), void* args) {
    Job* new_job = malloc(sizeof(Job));
    new_job->execute = work;
    new_job->params = args;
    new_job->next = NULL;
    new_job->done = false;

    if (*head == NULL) {
        *head = new_job;
    } else {
        Job* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_job;
    }
    process_job(new_job);
    while (!new_job->done) {
        // Busy waiting, potential for a race condition
    }
}