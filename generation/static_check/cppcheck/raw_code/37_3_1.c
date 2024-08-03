void StorePresentationURL(void *deviceContext, const char *presentationURL, int length) {
    struct UPnPDeviceContext *context = (struct UPnPDeviceContext *)deviceContext;
    if (length > 0 && presentationURL) {
        // Vulnerable to buffer overflow if length exceeds size of presURL
        memcpy(context->presURL, presentationURL, length);
        context->presURL[length] = '\0';
    }
    // Additional code for storing the presentation URL...
}