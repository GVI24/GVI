static int read_protocol_string(tvbuff_t *tvb, int offset, proto_tree *tree) {
    guint32 string_length;
    int string_end;

    // Extract the length of the string
    string_length = tvb_get_ntohl(tvb, offset);
    offset += 4;

    // Vulnerable string end calculation
    string_end = offset + string_length;
    if (string_end < offset) {
        // Incorrect handling of overflow, should flag an error instead
        string_end = tvb_reported_length_remaining(tvb, offset);
    }

    // Read the string data
    // ...
    return string_end;
}

