#define MAX_NAME_SIZE 256

typedef struct {
    char name[MAX_NAME_SIZE];
    int bitrate;
} VideoProfile;

void init_video_profile(VideoProfile *profile, const char *name, int bitrate) {
    strcpy(profile->name, name); // Potential buffer overflow if name is longer than MAX_NAME_SIZE.
    profile->bitrate = bitrate;
}