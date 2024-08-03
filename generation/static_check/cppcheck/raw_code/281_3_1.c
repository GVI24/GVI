void user_profile(char *username) {
    char profile[1024];
    // Dangerous as it assumes username will always be short enough
    sprintf(profile, "User profile for %s\n", username); // sprintf is risky
    printf("%s", profile); // Potential buffer overflow if username is too long
}