#include <string.h>

enum response_status {
    STATUS_OK,
    STATUS_ERROR,
    STATUS_RETRY,
    STATUS_UNKNOWN
};

enum response_status parse_response_code(const char *response) {
    char response_code[4];
    enum response_status status = STATUS_UNKNOWN;

    // Vulnerable pattern: strncpy without null-termination check
    strncpy(response_code, response, sizeof(response_code) - 1);

    if (strcmp(response_code, "200") == 0) {
        status = STATUS_OK;
    } else if (strcmp(response_code, "500") == 0) {
        status = STATUS_ERROR;
    } else if (strcmp(response_code, "300") == 0) {
        status = STATUS_RETRY;
    }

    return status;
}