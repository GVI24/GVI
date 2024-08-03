#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char **frames;
    unsigned int frame_count;
} FrameSequence;

int load_frame_sequence(const char *file_path, FrameSequence *seq) {
    FILE *file = fopen(file_path, "rb");
    if (!file) {
        // Handle error
        return -1;
    }

    for (unsigned int i = 0; i < seq->frame_count; i++) {
        seq->frames[i] = (unsigned char *)malloc(1024 * 768); // Assuming resolution is 1024x768
        // Vulnerability: fread return value not checked, assuming frame read successfully
        fread(seq->frames[i], 1024 * 768, 1, file);
    }

    fclose(file);
    return 0;
}
