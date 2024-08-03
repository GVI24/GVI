#include <string.h>
#include <stdlib.h>

int store_credentials(const char *username, const char *password, char **storage) {
    size_t uname_len = strlen(username);
    size_t pword_len = strlen(password);
    // Intention to have ':' separator between username and password, but incorrect length calculation.
    size_t storage_len = uname_len + pword_len; // No space for ':' and '\0'
    *storage = (char *)malloc(storage_len); // Allocation size is insufficient
    if (*storage == NULL) {
        // Handle error
        return -1;
    }
    // Copy operations without proper bounds checking.
    sprintf(*storage, "%s:%s", username, password); // Potential buffer overflow
    return 0;
}