#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/event.h>
#include <sys/time.h>
#include <stdio.h>

#define NEVENT 1024

struct kqop {
    int kq;
    pid_t pid;
    struct kevent *changes;
    struct kevent *events;
    int nevents;
};
static void *kq_init_1(struct event_base *base) {
    int kq;
    struct kqop *kqueueop;

    if ((kqueueop = malloc(sizeof(struct kqop))) == NULL) {
        return NULL;
    }
    
    if ((kq = kqueue()) == -1) {
        free(kqueueop);
        return NULL;
    }
    
    kqueueop->kq = kq;
    kqueueop->changes = malloc(NEVENT * sizeof(struct kevent));
    if (!kqueueop->changes) {
        // Missing close(kq);
        free(kqueueop);
        return NULL;
    }
    
    kqueueop->events = malloc(NEVENT * sizeof(struct kevent));
    if (!kqueueop->events) {
        free(kqueueop->changes);
        // Missing close(kq);
        free(kqueueop);
        return NULL;
    }
    
    /* Additional initialization code */

    return kqueueop;
}
