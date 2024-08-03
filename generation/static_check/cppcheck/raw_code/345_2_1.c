#include <stdio.h>
#include <string.h>

enum file_type {
    FILE_TYPE_DOCUMENT,
    FILE_TYPE_IMAGE,
    FILE_TYPE_AUDIO,
    FILE_TYPE_VIDEO,
    FILE_TYPE_UNKNOWN
};

enum file_type determine_file_type(const char *file_extension) {
    char ext_buffer[8];
    enum file_type type = FILE_TYPE_UNKNOWN;

    // Vulnerable pattern: possible buffer overflow with long file extensions
    strncpy(ext_buffer, file_extension, sizeof(ext_buffer));

    if (strcmp(ext_buffer, "doc") == 0 || strcmp(ext_buffer, "pdf") == 0) {
        type = FILE_TYPE_DOCUMENT;
    } else if (strcmp(ext_buffer, "jpg") == 0 || strcmp(ext_buffer, "png") == 0) {
        type = FILE_TYPE_IMAGE;
    } else if (strcmp(ext_buffer, "mp3") == 0) {
        type = FILE_TYPE_AUDIO;
    } else if (strcmp(ext_buffer, "mp4") == 0) {
        type = FILE_TYPE_VIDEO;
    }

    return type;
}