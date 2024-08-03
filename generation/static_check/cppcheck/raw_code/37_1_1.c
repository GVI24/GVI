void HandleEventURL(void *serviceData, const char *url, int urlLength) {
    struct UPnPServiceData *service = (struct UPnPServiceData *)serviceData;
    if (urlLength > 0) {
        // Vulnerable to buffer overflow if urlLength exceeds size of eventURL
        memcpy(service->eventURL, url, urlLength);
        service->eventURL[urlLength] = '\0';
    }
    // Additional code for event URL handling...
}

