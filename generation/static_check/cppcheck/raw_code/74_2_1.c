typedef struct {
    void (*callback)(void *);
    void *callback_data;
} event_handler;

void event_trigger_and_cleanup(event_handler *handler) {
    if (handler == NULL) {
        return;
    }
    handler->callback(handler->callback_data); // The callback might free handler->callback_data
    // Potential Use-After-Free: accessing handler->callback_data after callback
    if (handler->callback_data != NULL) {
        memset(handler->callback_data, 0, sizeof(handler->callback_data));
    }
}

