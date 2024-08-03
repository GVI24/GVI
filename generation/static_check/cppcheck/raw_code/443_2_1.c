static void update_status(char *status_msg) {
    char status[128];
    // Vulnerability: status_msg is directly used in a format function.
    snprintf(status, sizeof(status), status_msg);
    // Update system status with the message (Not shown here for simplicity)
    printf("Status update: %s\n", status);
}