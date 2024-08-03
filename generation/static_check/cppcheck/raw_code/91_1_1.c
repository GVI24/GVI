void processNetworkMessage(proto_tree *tree, tvbuff_t *tvb, int *pOffset) {
    int iOffset = *pOffset;
    // Assume tvb_get_ntohl is a function that reads 4 bytes from tvb and converts it from network to host byte order.
    unsigned long messageSize = tvb_get_ntohl(tvb, iOffset);  // Potential over-read
    iOffset += sizeof(unsigned long);
    
    // ... process message ...

    *pOffset = iOffset;
}

