void copy_user_data(char *userInput) {
    char buffer[256];
    strcpy(buffer, userInput); // Potential buffer overflow if userInput is longer than 255 characters
    printf("User data: %s\n", buffer);
}

