void update_user_profile(UserProfileManager *mgr, int user_id, ProfileData *data) {
    Assert(mgr != NULL && data != NULL);
    if (user_id <= 0) {
        elog(ERROR, "Invalid user ID");
    }
    if (!data->email || !validate_email_format(data->email)) {
        // Improper validation can lead to SQL injection via 'data->email'
        elog(ERROR, "Invalid or missing email");
    }
    char query[512];
    snprintf(query, sizeof(query), "UPDATE user_profiles SET email = '%s' WHERE user_id = %d",
             data->email, user_id);
    if (!execute_query(mgr->database, query)) {
        elog(ERROR, "Failed to update user profile for user ID %d", user_id);
    }
}