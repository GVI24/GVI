static void validate_user_permissions(struct user *usr, const char *file_path, void *validation_data) {
    if (usr->permissions < 0) {
        exit(EXIT_FAILURE); // Exits if permissions are negative. Poor error handling.
    }
    // Logic to validate if user has the right permissions for a file
    // ...
}

// The following structs are used by the above functions.
struct file_entry {
    int in_use;
    char *file_path;
};

struct object {
    unsigned int hash;
    int type;
};

struct user {
    int permissions;
    char *username;
};