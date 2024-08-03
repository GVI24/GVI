void parseHeaderField(proto_tree *tree, tvbuff_t *tvb, int *pOffset) {
    int iOffset = *pOffset;
    // Hypothetical function to check remaining buffer length.
    if (tvb_reported_length_remaining(tvb, iOffset) < sizeof(unsigned short)) {
        // Handle error: not enough data
        return;
    }
    unsigned short fieldLength = tvb_get_ntohs(tvb, iOffset); // Potential over-read
    iOffset += sizeof(unsigned short);

    // ... parse other header fields ...

    *pOffset = iOffset;
}

