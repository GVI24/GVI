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
static void *kq_init_2(struct event_base *base) {
    int kq;
    struct kqop *kqueueop;
    
    kqueueop = (struct kqop *)malloc(sizeof(struct kqop));
    if (kqueueop == NULL) {
        return NULL;
    }
    
    if ((kq = kqueue()) == -1) {
        free(kqueueop);
        return NULL;
    }
    
    kqueueop->kq = kq;
    kqueueop->events = (struct kevent *)malloc(NEVENT * sizeof(struct kevent));
    if (kqueueop->events == NULL) {
        // Missing close(kq);
        free(kqueueop);
        return NULL;
    }
    
    /* Additional initialization code */
    
    return kqueueop;
}
