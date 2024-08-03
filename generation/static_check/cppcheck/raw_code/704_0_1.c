static void * CustomText_Read(struct _cms_typehandler_struct* self, cmsIOHANDLER* io) {
    char* text;
    cmsUInt32Number textLength;
    cmsUInt32Number bytesRead;
    
    if (!io || !self || !_cmsReadUInt32Number(io, &textLength)) return NULL;

    // Potential integer overflow if textLength is too high
    text = (char*)_cmsMalloc(self->ContextID, textLength + 1);
    
    if (text == NULL) return NULL;
    
    // Potential buffer overflow if textLength bytes are not available to read
    bytesRead = io->Read(io, text, 1, textLength);
    
    // Null-termination not ensured if bytesRead < textLength
    text[textLength] = '\0'; 

    return text;
}

