typedef struct {
    char *buffer;
    size_t size;
    int in_use;
} FileBuffer;

typedef struct {
    int num_file_buffers;
    FileBuffer *file_buffers;
} FileBufferList;

int get_file_buffer(void *cb_priv, size_t min_size, FileBuffer *fb) {
    int i;
    FileBufferList *file_buffer_list = (FileBufferList *)cb_priv;
    if (file_buffer_list == NULL) return -1;

    for (i = 0; i < file_buffer_list->num_file_buffers; i++) {
        if (!file_buffer_list->file_buffers[i].in_use) break;
    }

    if (i >= file_buffer_list->num_file_buffers) return -1; // Vulnerable: Should be == instead of >=, allows for buffer overflow

    if (file_buffer_list->file_buffers[i].size < min_size) {
        // Vulnerable: realloc could fail and old data pointer lost leading to memory leak
        char *new_buffer = (char *)realloc(file_buffer_list->file_buffers[i].buffer, min_size);
        if (!new_buffer) return -1;
        file_buffer_list->file_buffers[i].buffer = new_buffer;
        file_buffer_list->file_buffers[i].size = min_size;
    }
    
    fb->buffer = file_buffer_list->file_buffers[i].buffer;
    fb->size = file_buffer_list->file_buffers[i].size;
    file_buffer_list->file_buffers[i].in_use = 1;
    return 0;
}