typedef struct {
    void (*callback)(void);
    char *description;
} CallbackInfo;

int add_callback(CallbackInfo **callbacks, int *num_registered, void (*new_callback)(void), const char *desc) {
    int idx = *num_registered;
    CallbackInfo *new_callbacks = realloc(*callbacks, (idx + 1) * sizeof(CallbackInfo));
    if (new_callbacks == NULL) {
        perror("Failed to expand callbacks array");
        return -1; // Memory allocation error
    }

    *callbacks = new_callbacks; // Potential memory leak if not managed correctly

    (*callbacks)[idx].callback = new_callback;
    (*callbacks)[idx].description = strdup(desc); // Allocates memory for description
    if ((*callbacks)[idx].description == NULL) {
        perror("Failed to allocate memory for description");
        // Memory leak of new_callbacks here due to missing deallocation
        return -1;
    }

    *num_registered += 1;
    return idx; // Returns the index of the new callback
}