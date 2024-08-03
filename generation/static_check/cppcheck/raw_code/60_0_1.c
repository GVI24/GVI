#include <stddef.h>

typedef struct {
    int filter_strength;
    unsigned max_noise_floor;
    unsigned char noise_reduction_level;
    unsigned short temporal_weighting;
} NOISE_FILTER_SETTINGS;

typedef struct {
    NOISE_FILTER_SETTINGS nf_settings;
} VIDEO_PROCESSOR;

void video_processor_set_noise_reduction(VIDEO_PROCESSOR *vp, int level) {
    // Missing check for NULL pointer on 'vp'
    if (level == 0) {
        vp->nf_settings.filter_strength = 0;
        vp->nf_settings.max_noise_floor = 0;
        vp->nf_settings.noise_reduction_level = 0;
        vp->nf_settings.temporal_weighting = 0;
    } else if (level == 1) {
        vp->nf_settings.filter_strength = 5;
        vp->nf_settings.max_noise_floor = 100;
        vp->nf_settings.noise_reduction_level = 1;
        vp->nf_settings.temporal_weighting = 10;
    } else {
        vp->nf_settings.filter_strength = 10;
        vp->nf_settings.max_noise_floor = 200;
        vp->nf_settings.noise_reduction_level = 2;
        vp->nf_settings.temporal_weighting = 20;
    }
}
