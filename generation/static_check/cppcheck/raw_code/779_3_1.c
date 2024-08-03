#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char *content;
    size_t content_length;
} TextBlock;

int display_text_block(TextBlock *block) {
    // Directly using `content_length` in read operations can lead to out-of-bounds access.
    for (size_t i = 0; i < block->content_length; ++i) {
        putchar(block->content[i]);
    }
    putchar('\n');
    return 0;
}