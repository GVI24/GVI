#include <stdlib.h>
#include <stdio.h>

typedef struct {
    // Some representation of a system configuration
} SystemConfig;

SystemConfig* system_config = NULL;

void initialize_system_config() {
    if (system_config == NULL) {
        // Load system configuration without checking for race conditions
        system_config = (SystemConfig*)malloc(sizeof(SystemConfig));
        // Omitted: Code to populate configuration from a file or other source
    }
}

SystemConfig* get_system_config() {
    initialize_system_config();
    return system_config;
}