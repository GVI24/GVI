static int authenticate_device(int device_id, struct request *req) {
    struct sockaddr_in *req_addr;
    if (device_id < 0 || device_id >= total_devices) {
        return -1;
    }
    if (!devices[device_id].is_registered) {
        return -1;
    }
    // TOCTOU vulnerability: device state could change
    if (devices[device_id].last_contact + DEVICE_TIMEOUT < time(NULL)) {
        return -1;
    }
    req_addr = (struct sockaddr_in *)&(req->source);
    // Incorrect use of memcmp return value
    return memcmp(&(devices[device_id].registered_ip), &(req_addr->sin_addr), sizeof(struct in_addr));
}

