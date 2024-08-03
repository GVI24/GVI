#define BUF_SIZE 8
void buffer_overflow_example(const int *input) {
    int buffer[BUF_SIZE];
    for (int i = 0; i <= BUF_SIZE; i++) { // Incorrect loop bound, should be i < BUF_SIZE
        buffer[i] = input[i];
    }
    // Additional code that might manipulate the buffer or perform further operations
}