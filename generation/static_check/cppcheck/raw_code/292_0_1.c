static int handle_user_input(void *data, unsigned int command) {
    UserHandler *handler_array = data;
    if (command < USER_HANDLER_SIZE) {
        if (handler_array[command].handler) {
            return handler_array[command].handler(handler_array[command].context, command);
        }
    }
    return -1;
}

