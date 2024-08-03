#include <stdio.h>
#include <stdlib.h>

void process_audio(int16_t *audio_samples, int num_samples) {
    int16_t *temp_buffer = (int16_t*)malloc(num_samples * sizeof(int16_t));
    if(temp_buffer == NULL) {
        perror("Allocation failed");
        return;
    }

    for (int i = 0; i < num_samples; i++) {
        temp_buffer[i] = audio_samples[i] / 2; // Simulate some processing.
    }

    free(temp_buffer); // Free the buffer

    // Vulnerable: Use after free. The temp_buffer is used after it has been freed.
    for (int i = 0; i < num_samples; i++) {
        audio_samples[i] = temp_buffer[i];
    }
}

int main() {
    int16_t audio_samples[100];
    process_audio(audio_samples, 100);
    return 0;
}