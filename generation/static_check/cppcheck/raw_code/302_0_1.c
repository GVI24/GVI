#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define MAX_DEVICES 10
#define DEVICE_NAME_LEN 64
#define SERIAL_NUMBER_LEN 32

typedef struct {
    char device_name[DEVICE_NAME_LEN];
    uint8_t *device_memory;
    size_t memory_size;
} Device;

Device device_list[MAX_DEVICES];

void register_device(char *input_data, size_t data_len) {
    static int device_count = 0;
    if (device_count >= MAX_DEVICES)
        return;

    uint8_t serial[SERIAL_NUMBER_LEN];

    // Vulnerability: no check if data_len exceeds SERIAL_NUMBER_LEN
    memcpy(serial, input_data, data_len);

    // Further operations with serial, possibly leading to buffer overflow exploitation
    printf("Device with serial number %s registered\n", serial);

    // Rest of the registration logic...

    device_count++;
}
