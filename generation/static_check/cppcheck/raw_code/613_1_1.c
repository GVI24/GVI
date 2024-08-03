#define MAX_HANDLES 50

typedef struct {
    void *handles[MAX_HANDLES];
    int handle_count;
} ResourceHolder;

void acquire_resource(ResourceHolder *holder, void *resource) {
    if (holder->handle_count < MAX_HANDLES) {
        holder->handles[holder->handle_count++] = resource;
    }
}

void release_all_resources(ResourceHolder *holder) {
    for (int i = 0; i < holder->handle_count; i++) {
        // Assume release_resource is a function that frees the resource
        release_resource(holder->handles[i]);
        holder->handles[i] = NULL;
    }
    holder->handle_count = 0;
}