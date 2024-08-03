typedef enum {
    COMPRESSION_LOW,
    COMPRESSION_MEDIUM,
    COMPRESSION_HIGH,
    COMPRESSION_TYPE_COUNT // Should not be used as a compression level.
} CompressionType;

int set_compression_level(int *level_array, CompressionType type) {
    // Vulnerability: COMPRESSION_TYPE_COUNT or out-of-range value can be passed as 'type'
    *level_array = type; // Potential out-of-bounds write if type is out of range
    return 0;
}

