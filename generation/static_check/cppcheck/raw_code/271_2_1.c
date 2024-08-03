char* generate_status_message(char *service_name, int status_code) {
    static char status_msg[BUFFER_SIZE];
    snprintf(status_msg, sizeof(status_msg), "The service %s is currently returning a status of %d",
             service_name, status_code);
    return status_msg;
}

