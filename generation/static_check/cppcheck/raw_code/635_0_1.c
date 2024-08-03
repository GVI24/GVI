int load_user_credentials(const char *filename) {
    FILE *fp;
    char buf[256];
    char username[64];
    char password[64];
    int userid;

    fp = fopen(filename, "r");
    if (!fp) {
        printf("Error opening file: %s\n", filename);
        return 0;
    }

    while (fgets(buf, sizeof(buf), fp)) {
        // Unsafe sscanf could lead to buffer overflow if input is too large
        sscanf(buf, "%d %63s %63s", &userid, username, password);
        // ... Additional logic for using the credentials ...
    }
    fclose(fp);
    return 1;
}

