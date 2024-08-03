#include <stdio.h>
#include <string.h>

void insecure_log(const char *msg) {
    char buffer[256];
    strcpy(buffer, msg); // No bounds checking; buffer overflow if msg is too long
    printf("Log: %s\n", buffer);
}

void log_encryption_status() {
    char status_msg[300];
    sprintf(status_msg, "Encryption initialized with version: %s", gcry_check_version(NULL)); // The resulting string may exceed the buffer size
    insecure_log(status_msg);
}