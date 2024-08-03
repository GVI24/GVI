int process_control_command(tvbuff_t *tvb, int offset, proto_tree *tree) {
    char command[100];
    guint8 commandLength;

    commandLength = tvb_get_guint8(tvb, offset);
    proto_tree_add_item(tree, hf_protocol_commandlength, tvb, offset, 1, ENC_BIG_ENDIAN);
    offset += 1;

    // Potential buffer overflow if commandLength is greater than the size of command[]
    tvb_memcpy(tvb, command, offset, commandLength);
    command[commandLength] = '\0'; // Null-terminate the string
    
    // Command processing logic goes here

    offset += commandLength;
    return offset;
}

