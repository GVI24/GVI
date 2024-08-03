void GenerateFontDescription(struct fontmetadata *metadata, char *description) {
    char desc_buffer[128];
    // Vulnerability: buffer overflow if description is too long
    sprintf(desc_buffer, "Description: %s", description);
    metadata->description = strdup(desc_buffer);
}

