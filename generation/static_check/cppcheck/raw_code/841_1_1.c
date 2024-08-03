void format_user_data(int userId, char *data) {
    char formattedData[100];
    sprintf(formattedData, "User ID: %d, Data: %s", userId, data); // Potential buffer overflow if data is too long
    printf("%s\n", formattedData);
}

