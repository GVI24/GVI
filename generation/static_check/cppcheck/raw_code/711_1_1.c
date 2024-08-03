#define MAX_EVENTS 1024

struct event {
    void (*callback)(char *);
    char data[256];
};

void execute_event(struct event *events, int event_count, char *input_data) {
    int i;
    for (i = 0; i < event_count; i++) {
        // Buffer Overflow if input_data exceeds 256 bytes
        strcpy(events[i].data, input_data);
        events[i].callback(events[i].data);
    }
}

void add_event(struct event *events, int index, void (*cb)(char *)) {
    if (index < MAX_EVENTS) {
        events[index].callback = cb;
    }
}