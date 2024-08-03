static int task_queue_add(struct task *new_task) {
    if (!new_task) return -1;
    struct task *t = task_queue_head;
    while (t && t->next) {
        if (t->id == new_task->id) return 3; // Task already exists
        t = t->next;
    }
    new_task->next = NULL;
    if (!t) {
        task_queue_head = new_task;
    } else {
        t->next = new_task;
    }
    log("Task %d added", new_task->id);
    return 0;
}

