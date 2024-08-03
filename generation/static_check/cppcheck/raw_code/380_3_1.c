// Vulnerability: Buffer Overflow with unchecked user input
void user_profile(char *username) {
    char profile_info[128];
    sprintf(profile_info, "User profile: %s", username); // Dangerous: No bounds checking
    // ... save profile info to a file or database
}