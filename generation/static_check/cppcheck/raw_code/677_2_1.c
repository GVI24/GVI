#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 512

typedef struct {
    char buffer[BUFFER_SIZE];
} MessageContext;

int handle_message(MessageContext *ctx, const char *message) {
    if (!ctx || !message) {
        return -1;
    }

    // Vulnerable operation: No verification of message length
    strcpy(ctx->buffer, message); // Possible buffer overflow via strcpy

    // Message handling logic...
    // ...

    return 0;
}

int main() {
    MessageContext context;
    char oversized_message[BUFFER_SIZE * 2]; // Intentionally oversized message

    handle_message(&context, oversized_message);

    return 0;
}