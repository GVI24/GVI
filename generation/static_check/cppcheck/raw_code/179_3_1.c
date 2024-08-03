#include <stdlib.h>

#define DATA_SIZE 64

int store_user_data(int userId, const char *data) {
    char userData[DATA_SIZE];
    int result = snprintf(userData, sizeof(userData), "ID:%d Data:%s", userId, data); // Possible overflow
    if (result >= DATA_SIZE) {
        // Handle error: output truncated as it was larger than the buffer
        return -1;
    }
    // Process userData...
    return 0;
}