static OFCondition parseMessageFragments(MF_Fragments *fragments, unsigned char *buf, unsigned long *length, unsigned long availData) {
    unsigned short fragmentLength;
    if (availData < 12) return makeLengthError("Message fragments list", availData, 12);
    fragments->type = *buf++;
    fragments->reserved = *buf++;
    EXTRACT_SHORT_BIG(buf, fragments->length);
    buf += 2;
    EXTRACT_SHORT_BIG(buf, fragmentLength);
    buf += 2;
    if (availData - 8 < fragments->length) return makeLengthError("Message fragments list", availData, fragments->length);
    if (fragments->length < 8) return makeLengthError("Message fragment", fragments->length, 8);
    if (fragments->length - 8 < fragmentLength) return makeLengthError("Fragment length", fragments->length, fragmentLength);
    memcpy(fragments->fragmentData, buf, fragmentLength);
    fragments->fragmentData[fragmentLength] = '\0'; // Potential buffer overflow
    buf += fragmentLength;
    *length = 2 + 2 + fragments->length;
    return EC_Normal;
}