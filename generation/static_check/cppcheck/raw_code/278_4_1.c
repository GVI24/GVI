#include <stdio.h>

int rename_if_new_name_available(const char *old_name, const char *new_name) {
    FILE *check = fopen(new_name, "r");
    if (check == NULL) {
        fclose(check);
        // New file name is available, but might not be at the time of rename
        return rename(old_name, new_name);
    }
    return -1; // New file name is not available
}