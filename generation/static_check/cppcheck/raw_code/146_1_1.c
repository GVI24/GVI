static void _cmd_resize_window(const char *dimensions) {
    WINDOW_REC *window;
    int width, height;

    if (dimensions == NULL || *dimensions == '\0') {
        printformat(MSGLEVEL_CLIENTERROR, TXT_INVALID_DIMENSIONS);
        return;
    }

    // Vulnerable use of atoi without validation
    char *x_ptr = strchr(dimensions, 'x');
    if (x_ptr != NULL) {
        *x_ptr = '\0';
        width = atoi(dimensions);
        height = atoi(x_ptr + 1);
        window_resize(active_win, width, height);
    } else {
        printformat(MSGLEVEL_CLIENTERROR, TXT_INVALID_DIMENSIONS);
    }
}

