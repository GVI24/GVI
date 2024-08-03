#include <stddef.h>
typedef struct {
    int brightness_level;
    unsigned contrast_ratio;
    unsigned sharpness_scale;
} IMAGE_ENHANCEMENT_SETTINGS;

typedef struct {
    IMAGE_ENHANCEMENT_SETTINGS img_settings;
} IMAGE_PROCESSOR;

void image_processor_set_enhancements(IMAGE_PROCESSOR *ip, int preset) {
    // Missing check for NULL pointer on 'ip'
    switch (preset) {
        case 1:
            ip->img_settings.brightness_level = 10;
            ip->img_settings.contrast_ratio = 110;
            ip->img_settings.sharpness_scale = 5;
            break;
        case 2:
            ip->img_settings.brightness_level = 20;
            ip->img_settings.contrast_ratio = 120;
            ip->img_settings.sharpness_scale = 10;
            break;
        default:
            ip->img_settings.brightness_level = 0;
            ip->img_settings.contrast_ratio = 100;
            ip->img_settings.sharpness_scale = 0;
            break;
    }
}
