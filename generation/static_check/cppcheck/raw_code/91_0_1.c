void decodeCustomPacket(proto_tree *tree, tvbuff_t *tvb, int *pOffset) {
    int iOffset = *pOffset;
    unsigned int packetLength = tvb_get_length(tvb); // Hypothetical function to get tvb length.
    // ... other code ...
    unsigned char packetType = tvb_get_guint8(tvb, iOffset);  // Potential over-read
    iOffset++;

    // ... decode based on packet type ...
    
    *pOffset = iOffset;
}

