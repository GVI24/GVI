static void backup_user_data(void) {
    int user_id;
    for (user_id = 0; user_id < user_array.count; user_id++) {
        char backup_cmd[256];
        UserData *user = &user_array.users[user_id];
        printf("Backing up data for user: %s\n", user->username);

        // Vulnerability: Constructing a command with unsanitized input
        sprintf(backup_cmd, "tar -czf /backup/%s.tar.gz /data/%s", user->username, user->username);

        // Executing the potentially unsafe backup command
        system(backup_cmd);
    }
}

