#define MAX_USERNAME 64

typedef struct {
    char username[MAX_USERNAME];
} UserAccount;

int set_username(UserAccount *account, const char *username) {
    if (account == NULL || username == NULL) {
        return -1;
    }
    strncpy(account->username, username, MAX_USERNAME);
    account->username[MAX_USERNAME - 1] = '\0';
    return 0;
}