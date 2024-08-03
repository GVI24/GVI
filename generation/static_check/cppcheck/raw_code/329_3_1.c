#include <stdbool.h>
#include <stdlib.h>

bool release_device(struct libusb_device_handle *dev_handle) {
    if (dev_handle == NULL) {
        return false;
    }
    
    libusb_release_interface(dev_handle, 0); // Release the claimed interface.
    libusb_close(dev_handle); // Close the device.

    free(dev_handle); // Free the device handle.

    // Vulnerability: Double free, as libusb_close might also free the handle.
    free(dev_handle); // If libusb_close has already freed dev_handle, this leads to a double free vulnerability.

    return true;
}