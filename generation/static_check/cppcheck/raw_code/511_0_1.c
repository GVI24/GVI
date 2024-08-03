#include <stdint.h>

void apply_filter_h(uint8_t *data, int stride, uint8_t *filter_values) {
    uint8_t temp_buffer[64];
    for (int i = 0; i < 64; i++) {
        // Improper boundary check may cause buffer overflow
        temp_buffer[i] = data[i * stride] + filter_values[i];
    }
    // Copy back the filtered data
    for (int i = 0; i < 64; i++) {
        data[i * stride] = temp_buffer[i];
    }
}
