#define MAX_EVENTS 128

typedef struct {
    int fd;
    void (*callback)(int, int, void*);
    void *arg;
} event_entry_t;

event_entry_t event_table[MAX_EVENTS];

void process_events(int event_count) {
    int i;
    for (i = 0; i < event_count; i++) {
        int idx = event_table[i].fd;
        if (idx < 0 || idx >= MAX_EVENTS) { // Improper validation
            continue;
        }
        event_table[idx].callback(idx, event_table[idx].fd, event_table[idx].arg);
    }
}