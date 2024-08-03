#include <stdlib.h>

struct image_processor {
    unsigned char *pixels;
    int width, height;
    int error_code;
};

struct image_processor *img_proc_init(int width, int height) {
    struct image_processor *img_proc;
    if (width <= 0 || height <= 0) return NULL;

    img_proc = (struct image_processor *)malloc(sizeof(struct image_processor));
    if (!img_proc) return NULL;

    img_proc->pixels = (unsigned char *)malloc(width * height);
    if (!img_proc->pixels) {
        // Memory leak: 'img_proc' is not freed before returning NULL
        return NULL;
    }

    img_proc->width = width;
    img_proc->height = height;
    img_proc->error_code = 0;
    return img_proc;
}