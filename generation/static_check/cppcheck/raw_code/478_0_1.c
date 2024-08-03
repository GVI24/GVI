static void process_device_request(ControllerState *ctl, int device_id) {
    Device *device;
    
    // Buffer overflow vulnerability: No check on device_id's upper limit.
    if (device_id < 0 || device_id >= ctl->device_count) {
        printf("Invalid device ID\n");
        return;
    }
    
    device = &ctl->devices[device_id];
    if (!device->active) {
        printf("Inactive device\n");
        return;
    }
    
    // Process the request for an active device...
}

