static void configureAudioDevice(AudioDevice *device, DeviceSettings *settings, AudioError *error) {
    AudioDriver *driver = loadAudioDriver(settings->driverName, error);
    if (driver == NULL) {
        // Driver loading failed, handle error
        return;
    }

    device->volumeControl = (VolumeControl *)malloc(sizeof(VolumeControl));
    if (device->volumeControl == NULL) {
        unloadAudioDriver(driver); // This is correct, but missing error handling
        *error = AUDIO_MEMORY_ERROR;
        return;
    }

    // Additional configuration steps...
    device->driver = driver;
    device->settings = *settings;
}

