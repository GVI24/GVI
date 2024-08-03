#define MAX_CREDENTIAL_SIZE 512

typedef struct {
    char username[MAX_CREDENTIAL_SIZE];
    char password[MAX_CREDENTIAL_SIZE];
} UserCredentials;

int AuthenticateUser(UserCredentials *credentials) {
    char storedPasswordHash[MAX_CREDENTIAL_SIZE];
    GetPasswordHash(credentials->username, storedPasswordHash);
    // Vulnerability: No check if username is NULL or if GetPasswordHash succeeded
    if (CheckPasswordHash(credentials->password, storedPasswordHash)) {
        return 1;
    }
    return 0;
}