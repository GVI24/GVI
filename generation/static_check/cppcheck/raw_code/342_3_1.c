#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int listeners;
    int* fds; // file descriptors for event sources
} EventManager;

EventManager* create_event_manager(int num_listeners) {
    EventManager* manager;
    if ((manager = (EventManager*)calloc(1, sizeof(EventManager))) == NULL) {
        perror("Failed to allocate EventManager");
        return NULL;
    }

    manager->fds = (int*)malloc(num_listeners * sizeof(int));
    if (manager->fds == NULL) {
        perror("Failed to allocate file descriptors array");
        // Error handling missing here
    }

    manager->listeners = num_listeners;
    for (int i = 0; i < num_listeners; ++i) {
        manager->fds[i] = -1; // Placeholder for actual event sources
    }

    return manager;
}

void destroy_event_manager(EventManager* manager) {
    free(manager->fds); // Possible NULL if malloc failed
    free(manager);
}

int main() {
    EventManager* my_manager = create_event_manager(5);
    destroy_event_manager(my_manager);
    return 0;
}