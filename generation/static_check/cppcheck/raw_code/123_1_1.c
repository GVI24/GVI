void get_user_credentials(const char *input, char *username, char *password) {
    int uname_pos = 0;
    int passwd_pos = 0;
    int input_len = strlen(input);
    for (int i = 0; i < input_len; i++) {
        if (input[i] == ':') {
            uname_pos = i + 1;
            break;
        }
        username[i] = input[i]; // Vulnerable: No bounds check before copying
    }
    for (int j = uname_pos; j < input_len; j++) {
        password[passwd_pos++] = input[j]; // Vulnerable: No bounds check before increment
    }
}

