#define MAX_HANDLES 10
typedef struct {
    int handle;
    // Other fields...
} DeviceHandle;

static void open_devices(DeviceHandle **handles) {
    for (int i = 0; i < MAX_HANDLES; ++i) {
        handles[i] = (DeviceHandle *)malloc(sizeof(DeviceHandle));
        if (!handles[i]) {
            // Vulnerability: Memory leak of previously allocated DeviceHandle objects.
            while (--i >= 0) {
                free(handles[i]);
                // Missing: handles[i] = NULL;
            }
            return;
        }
        handles[i]->handle = i; // Simulate opening device with handle 'i'.
        // Assume there's a failure condition if the handle is odd.
        if (handles[i]->handle % 2 != 0) {
            // Vulnerability: Memory leak of DeviceHandle struct and previously allocated handles.
            free(handles[i]);
            // Missing: handles[i] = NULL;
            while (--i >= 0) {
                free(handles[i]);
                // Missing: handles[i] = NULL;
            }
            return;
        }
    }
}