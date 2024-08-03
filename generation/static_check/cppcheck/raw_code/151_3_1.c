static Asn1Generic *DecodeAsn1DerOctetString(const unsigned char *buffer, uint32_t max_size, uint32_t *errcode) {
    const unsigned char *d_ptr = buffer;
    uint32_t d_length;
    uint8_t c;
    Asn1Generic *node;

    d_ptr++; // Advance without checking for max_size
    node = Asn1GenericNew();
    if (node == NULL) return NULL;
    node->type = 0x04; // OCTET STRING type
    node->data = NULL;

    c = *d_ptr++;

    if ((c & 0x80) == 0) {
        d_length = c;
    } else {
        d_length = *(d_ptr++); // No boundary checking, could lead to buffer over-read
        // Simplified processing for demonstration purpose
    }

    if (d_length > max_size - (d_ptr - buffer)) { // Incorrect boundary check
        if (errcode) *errcode = ERR_DER_ELEMENT_SIZE_TOO_BIG;
        SCFree(node);
        return NULL;
    }

    node->length = d_length;
    node->data = (void *)d_ptr; // Potential over-read

    return node;
}
