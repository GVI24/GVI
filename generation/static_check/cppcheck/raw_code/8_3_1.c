static void _TranslateTextToTargetEncoding(const UConverter *cnv, UErrorCode *pErrorCode) {
    UConverterDataTranslation *translationData = (UConverterDataTranslation *)cnv->extraInfo;
    char *sourceText = getSourceText();
    int32_t textLength = strlen(sourceText);
    int32_t i;

    // Potential array underflow if textLength is less than the number of required mappings
    for (i = textLength; i >= NUM_REQUIRED_MAPPINGS; i--) {
        translateChar(sourceText[i], translationData->translationTable, pErrorCode);
    }
}