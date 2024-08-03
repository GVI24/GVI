// Example handling multiple array accesses with insufficient checks
#define MAX_TASKS 8
typedef struct {
    uint32_t task_priorities[MAX_TASKS];
} TaskManager;

void task_set_priority(TaskManager* tm, uint32_t task_id, uint32_t priority) {
    if (task_id < MAX_TASKS && priority < 256) {
        // Assuming 8-bit priorities, although no explicit bit-width requirement is given
        tm->task_priorities[task_id] = priority;
    } else {
        printf("Invalid task ID or priority!\n");
    }
}

void task_unset_priority(TaskManager* tm, uint32_t task_id) {
    if (task_id == MAX_TASKS - 1) {
        tm->task_priorities[0] = 0; // Incorrect index used, should be task_id
    } else if (task_id < MAX_TASKS) {
        tm->task_priorities[task_id] = 0;
    }
    // Missing else branch; no message for out-of-bounds task_id
}
