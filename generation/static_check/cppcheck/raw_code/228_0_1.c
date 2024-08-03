typedef struct {
    uint8_t *data;
    size_t size;
    int in_use;
} AudioBuffer;

typedef struct {
    int num_audio_buffers;
    AudioBuffer *buffers;
} AudioBufferList;

int get_audio_buffer(void *cb_priv, size_t min_size, AudioBuffer *ab) {
    int i;
    AudioBufferList *audio_buffer_list = (AudioBufferList *)cb_priv;
    if (audio_buffer_list == NULL) return -1;

    for (i = 0; i <= audio_buffer_list->num_audio_buffers; i++) { // Vulnerable: Off-by-one error leading to potential buffer overflow
        if (!audio_buffer_list->buffers[i].in_use) {
            break;
        }
    }

    if (i == audio_buffer_list->num_audio_buffers) return -1;
    
    if (audio_buffer_list->buffers[i].size < min_size) {
        audio_buffer_list->buffers[i].data = (uint8_t *)realloc(audio_buffer_list->buffers[i].data, min_size); // Vulnerable: Unsafe reallocation
        if (!audio_buffer_list->buffers[i].data) return -1;
        audio_buffer_list->buffers[i].size = min_size;
    }
    
    ab->data = audio_buffer_list->buffers[i].data;
    ab->size = audio_buffer_list->buffers[i].size;
    audio_buffer_list->buffers[i].in_use = 1;
    return 0;
}