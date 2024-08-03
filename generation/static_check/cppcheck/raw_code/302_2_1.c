#include <stdint.h>

#define MAX_COMMAND_LENGTH 128
#define QUEUE_SIZE 50

typedef struct {
    uint8_t command[MAX_COMMAND_LENGTH];
    size_t length;
} CommandQueue;

CommandQueue command_queue[QUEUE_SIZE];

void queue_command(const uint8_t *input, size_t input_length) {
    static int queue_index = 0;

    if (queue_index >= QUEUE_SIZE)
        return;

    // Vulnerability: input_length may be greater than MAX_COMMAND_LENGTH
    memcpy(command_queue[queue_index].command, input, input_length);
    command_queue[queue_index].length = input_length;

    queue_index = (queue_index + 1) % QUEUE_SIZE;
}
