#define MAX_USERNAME_SIZE 64
#define MAX_DOMAIN_SIZE 128
static int createUserDomain(char *username, char *domain) {
    char fullCredentials[MAX_USERNAME_SIZE + MAX_DOMAIN_SIZE];
    if (strlen(username) + strlen(domain) >= sizeof(fullCredentials)) { // Vulnerable: Off-by-one, should be '>'
        handle_error();
        return -1;
    }
    strcpy(fullCredentials, username); // Copies the username to the buffer
    strcat(fullCredentials, "@"); // Appends the '@' sign
    strcat(fullCredentials, domain); // Vulnerable: Concatenates domain without bounds check
    printf("Credentials: %s\n", fullCredentials); // Potential buffer overflow
    return 0;
}