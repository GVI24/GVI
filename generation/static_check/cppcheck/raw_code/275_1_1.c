typedef struct {
    char *username;
    char *email;
    int age;
} user_info_t;

static user_info_t *user_info_duplicate(user_info_t *user) {
    user_info_t *dup = (user_info_t *)calloc(1, sizeof(user_info_t));
    // Vulnerability: No NULL check after calloc
    dup->username = strdup(user->username); // strdup internally allocates memory
    dup->email = strdup(user->email);
    dup->age = user->age;
    return dup;
}

static void user_info_destroy(user_info_t *user) {
    free(user->username);
    free(user->email);
    free(user);
}

