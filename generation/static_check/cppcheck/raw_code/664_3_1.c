static int parse_command_opcode(tvbuff_t *tvb, int offset, guint16 *opcode) {
    guint16 cmd_opcode = tvb_get_letohs(tvb, offset);
    switch (cmd_opcode) {
    case OPCODE_START:
        *opcode = OPCODE_START;
        break;
    case OPCODE_STOP:
        *opcode = OPCODE_STOP;
        break;
    case OPCODE_PAUSE:
        *opcode = OPCODE_PAUSE;
        break;
    case OPCODE_RESUME:
        *opcode = OPCODE_RESUME;
        break;
    default:
        DISSECTOR_ASSERT(FALSE);  // Vulnerability: Use of assertion
        break;
    }
    return offset + 2;
}