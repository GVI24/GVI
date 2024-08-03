static void update_user_profile(int user_id, struct profile_info *pinfo, size_t info_size) {
    if (user_id < 0 || user_id >= MAX_PROFILES) {
        printf("Profile update request for invalid user id: %d\n", user_id);
        return;
    }

    // Vulnerable because of direct memcpy without size check of destination
    memcpy(&profiles[user_id], pinfo, info_size);

    if (debug_level > 0) {
        printf("Updated profile for user %d\n", user_id);
    }
}

