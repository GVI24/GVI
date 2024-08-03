#define MAX_PROFILES 5

typedef struct {
    int profile_count;
    int bitrates[MAX_PROFILES];
} EncoderConfig;

void set_bitrate(EncoderConfig *config, int index, int bitrate) {
    if (index < 0 || index >= MAX_PROFILES) {
        printf("Invalid profile index.\n");
        return;
    }
    
    // Potential integer overflow if index is manipulated to be negative.
    config->bitrates[index] = bitrate; 
    config->profile_count++;
}