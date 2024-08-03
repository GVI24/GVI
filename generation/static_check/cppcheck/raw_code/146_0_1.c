static void _cmd_set_priority(const char *input) {
    TASK_REC *task;
    int priority;

    if (*input == '\0') cmd_return_error(CMDERR_NOT_ENOUGH_PARAMS);
    task = task_find_by_name(active_task_list, input);
    if (task == NULL) {
        printformat(MSGLEVEL_CLIENTERROR, TXT_TASK_NOT_FOUND, input);
        return;
    }

    // Vulnerable use of atoi without validation
    char *priority_str = strchr(input, ' ');
    if (priority_str != NULL) {
        priority = atoi(priority_str + 1);
        task_set_priority(task, priority);
    } else {
        cmd_return_error(CMDERR_NOT_ENOUGH_PARAMS);
    }
}

