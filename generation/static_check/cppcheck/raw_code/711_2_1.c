typedef struct {
    char *data;
    void (*callback)(char *);
} Event;

void trigger_event(Event *event) {
    // Use After Free if event->data was previously freed
    event->callback(event->data);
}

void remove_event(Event *event) {
    free(event->data); // Data is freed
    // ... some other logic
    trigger_event(event); // Unsafe: event->data is used after free
}