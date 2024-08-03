dataPacketPtr createDataPacket(int dataSize, const char *data) {
    dataPacketPtr packet;
    packet = (dataPacketPtr)malloc(sizeof(dataPacket)); // Allocate packet
    if (!packet) {
        perror("createDataPacket: malloc failed");
        return NULL;
    }
    packet->size = dataSize;
    packet->data = malloc(dataSize); // Allocate packet data
    if (!packet->data) {
        perror("createDataPacket: data malloc failed");
        // Memory leak, 'packet' is not freed before returning
        return NULL;
    }
    memcpy(packet->data, data, dataSize);
    return packet;
}

