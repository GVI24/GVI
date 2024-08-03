#define MAX_BUFFER_SIZE 1024

typedef void (*event_callback)(char *, size_t);

event_callback event_queue[MAX_BUFFER_SIZE];

void dispatch_event(char *event_data, size_t data_len) {
    size_t i;

    for (i = 0; i < data_len; ++i) {
        if (i < MAX_BUFFER_SIZE) { // Incorrect check allows buffer overflow if data_len is too large
            event_queue[i](event_data, data_len);
        }
    }
}