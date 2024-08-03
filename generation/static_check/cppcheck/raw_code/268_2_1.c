#include <stdio.h>

void process_audio_signal(int *buffer, int buffer_size, int limit) {
    int i, j, noise;
    for (i = 0; i < buffer_size; i += 2) {
        noise = rand() & limit; // Insecure random function usage
        buffer[i] += noise;  // Potential buffer overflow by incrementing index without check
        buffer[i + 1] += noise - (rand() % 5); // Potential buffer overflow
    }
}