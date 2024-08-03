#include <limits.h>

#define NUM_CHANNELS 3
#define MAX_VALUES 256

typedef struct {
    int channel_offsets[NUM_CHANNELS];
    int values[MAX_VALUES];
} ImageProcessor;

static void apply_channel_offsets(ImageProcessor *ip, int offset_base) {
    int channel, value_index;
    for (channel = 0; channel < NUM_CHANNELS; ++channel) {
        int channel_offset = offset_base + channel * 10;
        for (value_index = 0; value_index < MAX_VALUES; ++value_index) {
            int max_val = INT_MAX / channel_offset;
            ip->values[value_index] = ip->channel_offsets[value_index] < max_val 
                ? ip->channel_offsets[value_index] * channel_offset / 3 
                : INT_MAX;
        }
    }
}