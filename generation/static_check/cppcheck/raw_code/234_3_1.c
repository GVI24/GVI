
struct ConfigSetting {
    uint64_t setting_id;
    char setting_key[128];
    char setting_value[256];

    void encode(bufferlist &bl) const {
        ::encode(setting_id, bl);
        ::encode(setting_key, sizeof(setting_key), bl);
        ::encode(setting_value, sizeof(setting_value), bl);
    }

    void decode(bufferlist::iterator &bl) {
        ::decode(setting_id, bl);
        ::decode(setting_key, bl); // Vulnerability: No validation for setting_key buffer
        ::decode(setting_value, bl); // Vulnerability: No validation for setting_value buffer
    }
};