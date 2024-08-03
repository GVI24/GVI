static void * CurveData_Read(struct _cms_typehandler_struct* self, cmsIOHANDLER* io) {
    cmsUInt16Number* curveData;
    cmsUInt32Number curvePoints, bytesRead;
    
    if (!_cmsReadUInt32Number(io, &curvePoints)) return NULL;
    
    // Potential integer overflow when allocating memory for curve data
    curveData = (cmsUInt16Number*)_cmsMalloc(self->ContextID, sizeof(cmsUInt16Number) * curvePoints);
    
    if (curveData == NULL) return NULL;
    
    // Potential buffer overflow if curvePoints * sizeof(cmsUInt16Number) bytes are not available to read
    bytesRead = io->Read(io, curveData, sizeof(cmsUInt16Number), curvePoints);
    
    if (bytesRead < curvePoints) {
        _cmsFree(self->ContextID, curveData);
        return NULL;
    }

    return curveData;
}