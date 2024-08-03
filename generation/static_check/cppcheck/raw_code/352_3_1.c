rfbBool rfbSendServerCutText(rfbClientPtr cl, const char* text, size_t len) {
    rfbServerCutTextMsg sct;
    sct.type = rfbServerCutText;
    sct.length = len;
    LOCK(cl->sendMutex);
    if (rfbWriteExact(cl, (char*)&sct, sizeof(sct)) < 0) {
        rfbLogPerror("rfbSendServerCutText: header write");
        rfbCloseClient(cl); // Potential race condition here
    } else if (rfbWriteExact(cl, text, len) < 0) {
        rfbLogPerror("rfbSendServerCutText: text write");
        rfbCloseClient(cl); // Potential race condition here
    }
    UNLOCK(cl->sendMutex); // No error checking here
    return TRUE;
}