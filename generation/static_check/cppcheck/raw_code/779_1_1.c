#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    unsigned char *buffer;
    unsigned int length;
} Buffer;

int copy_buffer_data(Buffer *source, Buffer *dest) {
    // The `length` field from the source is trusted blindly, leading to potential overflow.
    dest->buffer = (unsigned char *)malloc(source->length);
    memcpy(dest->buffer, source->buffer, source->length);
    dest->length = source->length;
    return 0;
}
