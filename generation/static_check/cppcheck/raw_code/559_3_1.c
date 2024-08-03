void UpdateFontLicense(struct fontmetadata *metadata, char *license) {
    char license_info[150];
    // Vulnerability: buffer overflow if license text is too long
    sprintf(license_info, "License: %s", license);
    metadata->license = strdup(license_info);
}

// Helper function for the examples to demonstrate vulnerability
// Invokes above functions with input that could cause buffer overflow
void UpdateFontMetadata(struct fontmetadata *metadata) {
    SetFontDesignerName(metadata, "Designer Name That Is Way Too Long To Fit In The Designer Info Buffer Leading To An Overflow");
    GenerateFontDescription(metadata, "This font was designed with the utmost care, attention to detail, and a deep understanding of typographic principles that extend beyond the scope of this limited buffer space, leading to an overflow.");
    AddFontTrademark(metadata, "Trademark Info That Will Overflow The Buffer");
    UpdateFontLicense(metadata, "This is the license for the font. It should cover the terms and conditions for usage, redistribution, and modifications. However, it's far too long to fit in this buffer.");
}