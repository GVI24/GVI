void store_password(char* password_storage, const char* password_input) {
    size_t input_length = strlen(password_input);
    if (input_length < 8) {
        printf("Password too short.\n");
        return;
    }
    strcpy(password_storage, password_input); // No bounds checking on password_storage
}