#define MAX_INPUT_SIZE 1024
#define BUFFER_MULTIPLIER 2

void process_text_input(char* input_text) {
    char text_processing_buffer[MAX_INPUT_SIZE * BUFFER_MULTIPLIER];
    int input_length = strlen(input_text);
    if (input_length > MAX_INPUT_SIZE) {
        // Insecure handling of inputs larger than the maximum
        abort();
    }
    // Unsafe copy that does not consider BUFFER_MULTIPLIER limit
    strcpy(text_processing_buffer, input_text); // Potential stack overflow if input_length > MAX_INPUT_SIZE
    // Text processing logic... (omitted)
}