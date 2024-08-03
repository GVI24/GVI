#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *resource;
    unsigned int resource_port;
} control_message;

void setup_control_message(control_message *msg, const char *resource_name, unsigned int port) {
    size_t resource_length = strlen(resource_name);
    
    // Vulnerability: Memory allocation not checked for success
    msg->resource = (char *)malloc(resource_length + 1);

    if (resource_length < 20) {
        strcpy(msg->resource, resource_name);
        msg->resource_port = port;
    } else {
        // Missing deallocation when branch is taken
        printf("Resource name too long!\n");
    }

    // Not freeing resource in all code paths
}

int main() {
    control_message msg;
    setup_control_message(&msg, "ShortName", 4000);
    
    // Suppose we call the function again without freeing previous allocation
    setup_control_message(&msg, "ThisNameIsDefinitelyTooLongForTheBuffer", 4001);
    return 0;
}