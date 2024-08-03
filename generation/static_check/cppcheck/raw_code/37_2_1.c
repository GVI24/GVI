void SetServiceID(void *context, const char *id, int idLength) {
    struct UPnPContext *upnpContext = (struct UPnPContext *)context;
    if (id && idLength > 0) {
        // Vulnerable to buffer overflow if idLength exceeds size of serviceId
        memcpy(upnpContext->serviceId, id, idLength);
        upnpContext->serviceId[idLength] = '\0';
    }
    // Additional code for setting the service ID...
}

