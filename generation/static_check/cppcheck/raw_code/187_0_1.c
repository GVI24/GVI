#include <limits.h>

#define MAX_LEVELS 5
#define MAX_ELEMENTS 10

typedef struct {
    int level_multipliers[MAX_LEVELS];
    int adjustment_values[MAX_ELEMENTS];
} AudioProcessing;

static void set_audio_levels(AudioProcessing *proc, int base_level) {
    int level, element;
    for (level = 0; level < MAX_LEVELS; ++level) {
        int level_adjustment = base_level * (level + 1);
        int max_allowed = INT_MAX / level_adjustment;
        for (element = 0; element < MAX_ELEMENTS; ++element) {
            proc->adjustment_values[element] = proc->level_multipliers[element] < max_allowed 
                ? proc->level_multipliers[element] * level_adjustment / 2 
                : INT_MAX;
        }
    }
}