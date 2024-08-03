#include <stdio.h>
 
void print_log(const char *format) {
    char log_buffer[1024];
    sprintf(log_buffer, format); // Format string vulnerability
    printf("Log: %s\n", log_buffer);
}
 
int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <log message>\n", argv[0]);
        return 1;
    }
    print_log(argv[1]); // If argv[1] contains format specifiers, it could be exploited
    return 0;
}