typedef struct {
    uint8_t *pixels;
    size_t size;
    int in_use;
} ImageBuffer;

typedef struct {
    int num_image_buffers;
    ImageBuffer *img_buffers;
} ImageBufferList;

int get_image_buffer(void *cb_priv, size_t min_size, ImageBuffer *ib) {
    int i;
    ImageBufferList *img_buffer_list = (ImageBufferList *)cb_priv;
    if (img_buffer_list == NULL) return -1;

    // Vulnerable: Potential infinite loop if all buffers are in use
    while (1) { 
        for (i = 0; i < img_buffer_list->num_image_buffers; i++) {
            if (!img_buffer_list->img_buffers[i].in_use) goto found;
        }
    }
found:
    if (img_buffer_list->img_buffers[i].size < min_size) {
        img_buffer_list->img_buffers[i].pixels = realloc(img_buffer_list->img_buffers[i].pixels, min_size); // Vulnerable: realloc without null-check
        if (!img_buffer_list->img_buffers[i].pixels) return -1;
        img_buffer_list->img_buffers[i].size = min_size;
    }
    
    ib->pixels = img_buffer_list->img_buffers[i].pixels;
    ib->size = img_buffer_list->img_buffers[i].size;
    img_buffer_list->img_buffers[i].in_use = 1;
    return 0;
}