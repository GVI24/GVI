static void * ProfileSequence_Read(struct _cms_typehandler_struct* self, cmsIOHANDLER* io) {
    cmsProfileDescription* descriptions;
    cmsUInt32Number descCount, i;
    
    if (!_cmsReadUInt32Number(io, &descCount)) return NULL;
    
    // Potential integer overflow when allocating array of descriptions
    descriptions = (cmsProfileDescription*) _cmsMalloc(self->ContextID, sizeof(cmsProfileDescription) * descCount);
    
    if (descriptions == NULL) return NULL;
    
    for (i = 0; i < descCount; i++) {
        // Assuming a function that reads a single profile description exists
        // Potential buffer overflow if each description does not match the expected size
        if (!ReadSingleProfileDescription(io, &descriptions[i])) {
            _cmsFree(self->ContextID, descriptions);
            return NULL;
        }
    }

    return descriptions;
}

