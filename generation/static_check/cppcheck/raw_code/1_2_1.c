static void _FontManagerDestruct(FontManager *fm) {
    if (fm->fontData != NULL) {
        for (unsigned char idx = 0; idx < FM_MAX_FONTS; idx++) {
            if (fm->fontData->fonts[idx] != NULL) {
                fontUnload(fm->fontData->fonts[idx]);
            }
        }
        if (fm->fontDataShared) {
            freeSharedFontData(fm->fontData); // Frees fontData.
        }
    }
    // Some later code in the function...
    if (needsToUpdate(fm->fontData)) { // Use-after-free vulnerability.
        updateFontData(fm->fontData);
    }
}