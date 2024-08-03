void create_new_user(int argc, char *argv[]) {
    user_record new_user, existing_user;
    char *username = NULL;
    int user_exists = 0;
    
    if (argc < 2) {
        printf("Usage: create_new_user <username>\n");
        return;
    }
    
    memset(&existing_user, 0, sizeof(existing_user));
    username = argv[1];
    
    user_exists = get_user_by_name(username, &existing_user);
    if (user_exists) {
        printf("User '%s' already exists.\n", username);
        // Missing free operation for existing_user
        return;
    }
    
    // Initialize new user and perform operations...
    
cleanup:
    free_user_record(&new_user);
    // Missing free operation for existing_user
}

