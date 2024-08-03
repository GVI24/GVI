#include <stdlib.h>

#define MAX_DATA_LENGTH 2048

typedef struct {
    char *data;
    size_t length;
} CompressedData;

int decompress_data(CompressedData *comp_data, char *output) {
    char *comp_buffer = comp_data->data;
    int8_t *offset_table = (int8_t *)(comp_buffer + 12);
    size_t i;
    char current_byte, offset_index;
    
    if (comp_data->length > MAX_DATA_LENGTH) {
        // Error handling would go here
        return -1;
    }

    for (i = 0; i < comp_data->length; ++i) {
        offset_index = comp_buffer[i + 12] & 0xF;
        current_byte = output[i - 1] + offset_table[offset_index];
        output[i] = current_byte;
    }

    // Further processing would go here
    return (int)comp_data->length;
}