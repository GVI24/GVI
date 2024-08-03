static void edit_last_action(char **action_history, const char *last_action) {
    if (*action_history != NULL) {
        free(*action_history);  // Frees the existing action history
    }
    // Some more complex operation might happen here, not shown for brevity
    *action_history = strdup(last_action); // Allocates new memory for last_action
    // Potentially uses *action_history before strdup, leading to use-after-free
}