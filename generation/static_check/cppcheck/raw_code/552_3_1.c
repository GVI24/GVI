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
static void *kq_init_4(struct event_base *base) {
    int kq;
    struct kqop *kqueueop;
    
    if (!(kqueueop = malloc(sizeof(struct kqop)))) {
        return NULL;
    }
    
    if ((kq = kqueue()) == -1) {
        // File descriptor `kq` is leaked here
        free(kqueueop);
        return NULL;
    }
    
    kqueueop->kq = kq;
    kqueueop->nevents = NEVENT;
    kqueueop->changes = malloc(NEVENT * sizeof(struct kevent));
    if (kqueueop->changes == NULL) {
        // Missing close(kq);
        free(kqueueop);
        return NULL;
    }
    
    kqueueop->events = malloc(NEVENT * sizeof(struct kevent));
    if (kqueueop->events == NULL) {
        free(kqueueop->changes);
        // Missing close(kq);
        free(kqueueop);
        return NULL;
    }
    
    /* Additional initialization code */
    
    return kqueueop;
}