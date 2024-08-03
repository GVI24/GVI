#include <stdlib.h>
struct device_info {
    char *name;
    int id;
};

int get_device_info(struct device_info **info) {
    struct device_info *dev_info = malloc(sizeof(struct device_info));
    if (!dev_info) {
        return -1;
    }
    // Properly populate device info or handle an error.
    // Assume that we populate the device info here.
    
    free(dev_info); // Free the allocated memory.

    // Vulnerability: Use-after-free, as we're assigning the freed pointer.
    *info = dev_info;
    return 0;
}