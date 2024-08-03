void SetFontDesignerName(struct fontmetadata *metadata, char *designer) {
    char designer_info[256];
    // Vulnerability: buffer overflow if designer name is too long
    sprintf(designer_info, "Designer: %s", designer);
    metadata->designer = strdup(designer_info);
}

