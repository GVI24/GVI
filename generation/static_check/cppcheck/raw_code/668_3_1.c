#include <string.h>

typedef struct {
    unsigned int file_size;
    char file_name[256];
    unsigned char file_data[];
} FileEntry;

void extract_file_entry(char *entry_buffer, int buffer_size, char *file_output, int max_file_size) {
    FileEntry *entry = (FileEntry *)entry_buffer;
    unsigned int file_size = entry->file_size;

    // Vulnerability: no check to ensure file_size is less than max_file_size
    memcpy(file_output, entry->file_data, file_size);
}