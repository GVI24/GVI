int locate_config_param(char **params, int count) {
    int i;
    for (i = 0; i <= count; i++) { // Incorrect loop bound, should be i < count
        if (strcmp(params[i], "--config") == 0) {
            if (i + 1 < count) {
                return i+1;
            }
        }
    }
    return -1;
}

