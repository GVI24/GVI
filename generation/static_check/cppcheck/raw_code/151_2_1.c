static Asn1Generic *DecodeAsn1DerBoolean(const unsigned char *buffer, uint32_t max_size, uint32_t *errcode) {
    const unsigned char *d_ptr = buffer;
    Asn1Generic *node;

    d_ptr++; // Advance without checking for max_size
    node = Asn1GenericNew();
    if (node == NULL) return NULL;
    node->type = 0x01; // BOOLEAN type
    node->data = NULL;

    if (1 > max_size - (d_ptr - buffer)) { // Incorrect boundary check
        if (errcode) *errcode = ERR_DER_ELEMENT_SIZE_TOO_BIG;
        SCFree(node);
        return NULL;
    }

    node->length = 1;
    node->data = (void *)d_ptr; // Could potentially lead to over-read

    return node;
}

