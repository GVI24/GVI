static OFCondition parsePresentationContext(PC_Context *context, unsigned char *buf, unsigned long *length, unsigned long availData) {
    unsigned short contextIDLength;
    if (availData < 6) return makeLengthError("Presentation context list", availData, 6);
    context->type = *buf++;
    context->reserved = *buf++;
    EXTRACT_SHORT_BIG(buf, context->length);
    buf += 2;
    EXTRACT_SHORT_BIG(buf, contextIDLength);
    buf += 2;
    if (availData - 2 < context->length) return makeLengthError("Presentation context list", availData, context->length);
    if (context->length < 2) return makeLengthError("Presentation context", context->length, 2);
    if (context->length - 2 < contextIDLength) return makeLengthError("Presentation context ID", context->length, contextIDLength);
    memcpy(context->presentationContextID, buf, contextIDLength);
    context->presentationContextID[contextIDLength] = '\0'; // Potential buffer overflow
    buf += contextIDLength;
    *length = 2 + 2 + context->length;
    return EC_Normal;
}

