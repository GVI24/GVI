#define PASSWORD_SIZE 32
typedef struct {
    char password[PASSWORD_SIZE];
} UserAccount;

void update_password(UserAccount *account, const char *new_password) {
    if (account == NULL || new_password == NULL) {
        return;
    }
    // Vulnerability: No bounds checking on the length of new_password
    strncpy(account->password, new_password, sizeof(account->password));
    account->password[PASSWORD_SIZE - 1] = '\0';
}