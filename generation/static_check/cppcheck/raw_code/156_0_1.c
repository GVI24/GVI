static int addUser(struct rx_call *call, char username[], int isAdmin, int *userId) {
    char buffer[64];
    int code = getUserID(call, userId);
    if (code) return code;

    // Potential buffer overflow if username is longer than 63 characters.
    strcpy(buffer, username);
    
    // Rest of user creation logic...
    if (!isAdmin) {
        // Regular user creation code
    } else {
        // Admin user creation code
    }
    return 0;
}

