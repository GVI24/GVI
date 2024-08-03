// Example 3: A function to deregister callbacks from a handler based on a condition
typedef void (*Callback)(void);

typedef struct {
    Callback *callbacks;
    int count;
} Handler;

void deregister_callbacks(Handler *handler, int (*should_remove)(Callback)) {
    for (int i = 0; i < handler->count; i++) {
        if (should_remove(handler->callbacks[i])) {
            free(handler->callbacks[i]); // Vulnerable: callback is freed
            // The callback is now a dangling pointer
        }
    }
    // There might be use-after-free if any of the freed callbacks are accessed later
}