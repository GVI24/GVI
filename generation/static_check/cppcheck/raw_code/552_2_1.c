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
static void *kq_init_3(struct event_base *base) {
    int kq;
    struct kqop *kqueueop;
    
    kqueueop = (struct kqop *)calloc(1, sizeof(struct kqop));
    if (!kqueueop) {
        return NULL;
    }
    
    if ((kq = kqueue()) == -1) {
        free(kqueueop); // Missing close(kq);
        return NULL;
    }
    
    kqueueop->kq = kq;
    kqueueop->changes = (struct kevent *)calloc(NEVENT, sizeof(struct kevent));
    if (!kqueueop->changes) {
        free(kqueueop);
        return NULL;
    }
    
    kqueueop->events = (struct kevent *)calloc(NEVENT, sizeof(struct kevent));
    if (!kqueueop->events) {
        free(kqueueop->changes);
        free(kqueueop);
        return NULL;
    }
    
    /* Additional initialization code */
    
    return kqueueop;
}
