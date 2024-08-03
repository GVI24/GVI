static Asn1Generic *DecodeAsn1DerInteger(const unsigned char *buffer, uint32_t max_size, uint32_t *errcode) {
    const unsigned char *d_ptr = buffer;
    uint32_t d_length;
    Asn1Generic *node;

    d_ptr++; // Advance without checking for max_size
    node = Asn1GenericNew();
    if (node == NULL) return NULL;
    node->type = 0x02; // INTEGER type
    node->data = NULL;

    d_length = *d_ptr++; // No validation of the length against the buffer size

    if (d_length > max_size) { // Check after incrementing
        if (errcode) *errcode = ERR_DER_ELEMENT_SIZE_TOO_BIG;
        SCFree(node);
        return NULL;
    }

    node->length = d_length;
    node->data = (void *)d_ptr; // Potential over-read

    return node;
}

