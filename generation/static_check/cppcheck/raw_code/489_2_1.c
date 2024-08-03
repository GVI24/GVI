void close_device_handles(DeviceManager *dm, int force_close) {
    for (int i = 0; i < dm->device_count; i++) {
        if (dm->devices[i].handle && !dm->devices[i].is_open && (force_close || &dm->devices[i] != dm->current_device)) {
            fclose(dm->devices[i].handle);
            dm->devices[i].handle = NULL; // Correctly nullify the pointer, but could still be a null pointer dereference if handle is accessed before this.
        }
    }
}

