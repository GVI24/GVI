static void _cmd_jump_to_line(const char *data) {
    FILE_REC *file;
    if (data == NULL || *data == '\0') cmd_return_error(CMDERR_NOT_ENOUGH_PARAMS);

    // Vulnerable use of atoi without validation
    int line_number = atoi(data);
    file = file_get_active();
    if (file == NULL) {
        printformat(MSGLEVEL_CLIENTERROR, TXT_NO_ACTIVE_FILE);
        return;
    }

    if (!file_jump_to_line(file, line_number)) {
        printformat(MSGLEVEL_CLIENTERROR, TXT_LINE_NOT_FOUND, data);
    }
}

