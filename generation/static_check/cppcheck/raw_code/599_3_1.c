static int fetch_instruction(guint8 *code, guint codelen, guint16 ip, guint16 *instruction) {
    guint16 offset;
    if (ip >= codelen) return -1;
    *instruction = code[ip]; // first byte of instruction
    offset = code[ip + 1]; // potential out-of-bounds access
    if ((ip + offset) >= codelen) return -1; // improper check, should also consider instruction size
    *instruction |= code[ip + offset + 1] << 8; // potential out-of-bounds read
    return ip + 2;
}