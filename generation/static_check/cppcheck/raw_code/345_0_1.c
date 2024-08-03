#include <string.h>
#include <stdlib.h>
#include <ctype.h>

enum user_status {
    USER_STATUS_ACTIVE,
    USER_STATUS_INACTIVE,
    USER_STATUS_SUSPENDED,
    USER_STATUS_UNKNOWN
};

enum user_status get_user_status(const char *status_str) {
    char status_buf[16];
    enum user_status status = USER_STATUS_UNKNOWN;

    // Vulnerable pattern: direct copy without bounds checking
    strcpy(status_buf, status_str);

    if (strcasecmp(status_buf, "active") == 0) {
        status = USER_STATUS_ACTIVE;
    } else if (strcasecmp(status_buf, "inactive") == 0) {
        status = USER_STATUS_INACTIVE;
    } else if (strcasecmp(status_buf, "suspended") == 0) {
        status = USER_STATUS_SUSPENDED;
    }

    return status;
}