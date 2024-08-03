static void update_user_profile(char *user_dir, struct profile *p) {
    char profile_path[256];
    snprintf(profile_path, sizeof(profile_path), "%s/profile.txt", user_dir); // Potential buffer overflow if user_dir too long
    FILE *profile_file = fopen(profile_path, "w+");
    
    if (profile_file == NULL) {
        fprintf(stderr, "Unable to open profile file at %s\n", profile_path);
        return;
    }
    
    fprintf(profile_file, "User ID: %s\nName: %s\nBio: %s\n", p->user_id, p->name, p->bio); // Assuming profile struct has these fields
    fclose(profile_file);
}