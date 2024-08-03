static OFCondition parseImageSet(IS_Set *imageSet, unsigned char *buf, unsigned long *length, unsigned long availData) {
    unsigned short imageSetLength;
    if (availData < 10) return makeLengthError("Image set list", availData, 10);
    imageSet->flag = *buf++;
    imageSet->reserved1 = *buf++;
    EXTRACT_SHORT_BIG(buf, imageSet->length);
    buf += 2;
    EXTRACT_SHORT_BIG(buf, imageSetLength);
    buf += 2;
    if (availData - 6 < imageSet->length) return makeLengthError("Image set list", availData, imageSet->length);
    if (imageSet->length < 6) return makeLengthError("Image set", imageSet->length, 6);
    if (imageSet->length - 6 < imageSetLength) return makeLengthError("Image set length", imageSet->length, imageSetLength);
    memcpy(imageSet->imageSetID, buf, imageSetLength);
    imageSet->imageSetID[imageSetLength] = '\0'; // Potential buffer overflow
    buf += imageSetLength;
    imageSet->reserved2 = *buf++;
    *length = 2 + 2 + imageSet->length;
    return EC_Normal;
}

