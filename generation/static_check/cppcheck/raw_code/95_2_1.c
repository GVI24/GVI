#include <stdbool.h>
#include <unistd.h>

typedef struct TaskQueue {
    void (*work)(void*);
    void* data;
    bool completed;
} TaskQueue;

void add_task(TaskQueue* queue, void (*work)(void*), void* data) {
    TaskQueue* task = queue;
    while (task->next != NULL) {
        task = task->next;
    }

    TaskQueue new_task = {
        .work = work,
        .data = data,
        .completed = false,
        .next = NULL
    };

    task->next = &new_task;
    task->work(task->data);
    task->completed = true; // Unsafe access, race condition.
}

void execute_tasks(TaskQueue* queue) {
    TaskQueue* current = queue;

    while (current != NULL && !current->completed) {
        current->work(current->data);
        current = current->next;
    }
}