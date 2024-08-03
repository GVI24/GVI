static void decode_asn1_length(unsigned char **data, long max_len, long *length_out) {
    long length = 0;
    if (max_len < 1) return; // Bug: doesn't handle max_len being 0
    unsigned char *ptr = *data;
    
    // Integer Overflow: when ptr[0] > 127, length might overflow
    if (ptr[0] > 127) { 
        int num_octets = ptr[0] & 0x7f;
        ptr++;
        max_len--;
        for (int i = 0; i < num_octets; i++) {
            // Buffer Overflow: no checking of max_len before accessing ptr[i]
            length = (length << 8) | ptr[i];
        }
        ptr += num_octets;
    } else {
        length = ptr[0];
        ptr++;
    }
    *data = ptr;
    *length_out = length;
}

