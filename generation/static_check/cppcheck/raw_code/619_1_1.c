void reset_password(int argc, char *argv[]) {
    user_account acct;
    char *username;
    char new_password[256];
    
    if (argc < 3) {
        printf("Usage: reset_password <username> <new_password>\n");
        return;
    }
    
    username = argv[1];
    if (!validate_username(username)) {
        printf("Invalid username format.\n");
        return;
    }
    
    strcpy(new_password, argv[2]); // Potential buffer overflow vulnerability
    
    if (get_user_account(username, &acct)) {
        update_password(&acct, new_password);
        printf("Password reset for user '%s'.\n", username);
    } else {
        printf("User '%s' not found.\n", username);
    }
    
    // Missing free operation for acct
}

