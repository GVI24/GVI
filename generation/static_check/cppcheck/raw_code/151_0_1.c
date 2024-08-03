static Asn1Generic *DecodeAsn1DerSequence(const unsigned char *buffer, uint32_t max_size, uint8_t depth, uint32_t *errcode) {
    const unsigned char *d_ptr = buffer;
    uint32_t d_length, numbytes;
    uint8_t c;
    Asn1Generic *node;

    d_ptr++; // Advance without checking for max_size
    node = Asn1GenericNew();
    if (node == NULL) return NULL;
    node->type = ASN1_SEQUENCE;
    node->data = NULL;

    c = *d_ptr++; // Increment pointer without checking max_size

    if ((c & 0x80) == 0) {
        d_length = c;
    } else {
        numbytes = c & 0x7F;
        if (DecodeAsn1BuildValue(&d_ptr, &d_length, numbytes, errcode) == -1) {
            SCFree(node);
            return NULL;
        }
    }

    node->length = d_length + (d_ptr - buffer);
    if (node->length > max_size) { // Check after incrementing may lead to over-read
        if (errcode) *errcode = ERR_DER_ELEMENT_SIZE_TOO_BIG;
        SCFree(node);
        return NULL;
    }

    // Simplified processing for demonstration purpose
    node->data = (void *)d_ptr; // Potential over-read if d_ptr exceeds buffer limits

    return node;
}

