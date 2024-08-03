void update_user_profile(char *data, int data_size, int user_id) {
    char profile_info[128];
    if (user_id < 0 || user_id >= total_users) return;
    struct user_account *acc = get_user_account(user_id);
    if (acc == NULL) return;

    // Vulnerable: profile_info might be overflowed by large data_size values
    memcpy(profile_info, data, data_size);
    printf("Profile updated for user %d\n", user_id);
    store_user_profile_info(user_id, profile_info);
}

