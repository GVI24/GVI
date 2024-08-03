static OFCondition parseTransferSyntaxes(TSR_TransferSyntaxes *syntax, unsigned char *buf, unsigned long *length, unsigned long availData) {
    unsigned short syntaxLength;
    if (availData < 8) return makeLengthError("Transfer syntax list", availData, 8);
    syntax->type = *buf++;
    syntax->reserved = *buf++;
    EXTRACT_SHORT_BIG(buf, syntax->length);
    buf += 2;
    EXTRACT_SHORT_BIG(buf, syntaxLength);
    buf += 2;
    if (availData - 4 < syntax->length) return makeLengthError("Transfer syntax list", availData, syntax->length);
    if (syntax->length < 4) return makeLengthError("Transfer syntax list", syntax->length, 4);
    if (syntax->length - 4 < syntaxLength) return makeLengthError("Transfer syntax", syntax->length, syntaxLength);
    memcpy(syntax->transferSyntaxUID, buf, syntaxLength);
    syntax->transferSyntaxUID[syntaxLength] = '\0';
    buf += syntaxLength;
    *length = 2 + 2 + syntax->length;
    return EC_Normal;
}

