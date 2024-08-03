#define PROFILE_SIZE 128
typedef struct {
    char user_profile[PROFILE_SIZE];
} UserProfile;

void set_user_profile(UserProfile *profile, const char *details) {
    if (profile == NULL || details == NULL) {
        return;
    }
    // Vulnerability: No bounds checking on the length of details
    strncpy(profile->user_profile, details, sizeof(profile->user_profile));
    profile->user_profile[PROFILE_SIZE - 1] = '\0';
}

