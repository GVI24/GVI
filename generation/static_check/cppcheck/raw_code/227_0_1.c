#include <stdio.h>
#include <string.h>

typedef struct {
    char username[64];
} User;

void setUsername(User *user, const char *newUsername) {
    // Vulnerable: No bounds checking on the length of newUsername
    strcpy(user->username, newUsername);
}

int main() {
    User user;
    // A username longer than 64 chars can overflow the buffer
    const char *longUsername = "very_long_username_that_will_overflow_the_buffer_in_the_user_struct";
    setUsername(&user, longUsername);
    return 0;
}