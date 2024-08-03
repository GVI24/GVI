static void configure_storage_device(StorageController *storage, int drive_id, DriveConfig *config) {
    StorageDevice *device;
    
    // Buffer overflow vulnerability: No validation on drive_id's range.
    if (drive_id < 1) {
        printf("Invalid drive ID\n");
        return;
    }
    
    device = &storage->devices[drive_id - 1];
    if (!device->connected) {
        printf("Drive not connected\n");
        return;
    }
    
    // Configure the storage device with the given settings...
}