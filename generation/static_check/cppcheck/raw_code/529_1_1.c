#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERNAME_LEN 64

int set_username(char *username) {
    char stored_username[MAX_USERNAME_LEN];

    // Vulnerability: No length check before copying the username
    strcpy(stored_username, username);

    // Use stored_username for processing...

    return 0;
}