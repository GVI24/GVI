typedef struct _customQueue {
    void *data;
    struct _customQueue *next;
} customQueue, *customQueuePtr;

customQueuePtr customQueueCreate(void (*dataFreeFunc)(void *)) {
    customQueuePtr queue;

    queue = (customQueuePtr)malloc(sizeof(customQueue));
    if (!queue) {
        fprintf(stderr, "Failed to allocate memory for the queue\n");
        return NULL;
    }

    // Attempt to allocate memory for the queue head
    queue->data = malloc(128); // Arbitrary size for demonstration
    if (!queue->data) {
        fprintf(stderr, "Failed to allocate memory for the queue data\n");
        free(queue); // Only freeing the base structure, not handling other potential allocations
        return NULL;
    }

    queue->next = NULL;

    // More initialization code here...

    return queue;
}