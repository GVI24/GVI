
struct DeviceInfo {
    uint64_t device_id;
    char device_name[256];
    char device_secret[256];

    void encode(bufferlist &bl) const {
        ::encode(device_id, bl);
        ::encode(device_name, sizeof(device_name), bl);
        ::encode(device_secret, sizeof(device_secret), bl);
    }

    void decode(bufferlist::iterator &bl) {
        ::decode(device_id, bl);
        ::decode(device_name, bl); // Vulnerability: Lack of buffer size validation
        ::decode(device_secret, bl); // Vulnerability: Lack of buffer size validation
    }
};


