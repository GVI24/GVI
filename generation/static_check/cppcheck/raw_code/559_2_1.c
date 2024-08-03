void AddFontTrademark(struct fontmetadata *metadata, char *trademark) {
    char trademark_info[100];
    // Vulnerability: buffer overflow if trademark info is too long
    sprintf(trademark_info, "Trademark %s All rights reserved", trademark);
    metadata->trademark = strdup(trademark_info);
}

