#include <pthread.h>

// Simplified logger structure
typedef struct {
    // Logger state and configuration
    int initialized;
} Logger;

Logger* global_logger = NULL;

Logger* get_logger_instance() {
    if (global_logger == NULL) {
        // Unsafe lazy initialization of global resource
        global_logger = (Logger*)malloc(sizeof(Logger));
        global_logger->initialized = 1; // Assume logger is now initialized
    }
    return global_logger;
}