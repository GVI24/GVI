static void _HandleCharacterConversion(const UConverter *cnv, const UChar *input, int32_t inputLength, UErrorCode *pErrorCode) {
    UConverterDataCharConversion *convData = (UConverterDataCharConversion *)cnv->extraInfo;
    int32_t counter;

    // Potential buffer overflow if inputLength exceeds the bounds of convData->outputBuffer
    for (counter = 0; counter < inputLength; counter++) {
        convData->outputBuffer[counter] = convertCharToTargetEncoding(input[counter], pErrorCode);
    }
}

