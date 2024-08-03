#define USERNAME_MAX 32
void mock_login() {
    char username[USERNAME_MAX];
    char password[USERNAME_MAX];
    int uname_index = 0;
    int passwd_index = 0;
    char input_char;

    printf("Enter username: ");
    while ((input_char = getchar()) != '\n' && input_char != EOF) {
        username[uname_index++] = input_char; // No checking against USERNAME_MAX
    }
    username[uname_index] = '\0';

    printf("Enter password: ");
    while ((input_char = getchar()) != '\n' && input_char != EOF) {
        password[passwd_index++] = input_char; // No checking against USERNAME_MAX
    }
    password[passwd_index] = '\0';

    printf("Credentials stored (unsafely!)\n");
}