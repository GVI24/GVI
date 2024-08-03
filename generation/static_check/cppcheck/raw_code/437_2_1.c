typedef struct {
    char *name;
    int id;
} User;

void deleteUser(User *user) {
    free(user->name);
    // Use-after-free: attempting to print 'name' after it has been freed.
    printf("Deleted user: %s\n", user->name);
    free(user);
}