bool extract_user_data(session_t *s) {
    char userdata[MAX_STRING_SIZE];
    if (sscanf(s->buffer, "DATA %s", userdata) != 1) {
        printf("Error extracting user data.\n");
        return false;
    }
    printf("User data extracted: %s\n", userdata);
    return true;
}

