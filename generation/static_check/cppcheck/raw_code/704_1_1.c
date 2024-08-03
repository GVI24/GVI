static void * ArrayOfValues_Read(struct _cms_typehandler_struct* self, cmsIOHANDLER* io, cmsUInt32Number count) {
    cmsFloat64Number* values;
    cmsUInt32Number i, bytesRead;
    
    // Potential integer overflow when calculating buffer size
    values = (cmsFloat64Number*)_cmsMalloc(self->ContextID, count * sizeof(cmsFloat64Number));
    
    if (values == NULL) return NULL;
    
    // Potential buffer overflow if count * sizeof(cmsFloat64Number) bytes are not available to read
    for(i = 0; i < count; i++) {
        if (!_cmsReadFloat64Number(io, &values[i])) {
            _cmsFree(self->ContextID, values);
            return NULL;
        }
    }

    return values;
}

