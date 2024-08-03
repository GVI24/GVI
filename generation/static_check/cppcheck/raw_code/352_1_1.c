rfbBool rfbSendKeyEvent(rfbClientPtr cl, uint32_t key, uint8_t down) {
    rfbKeyboardEventMsg kev;
    kev.type = rfbKeyboardEvent;
    kev.downFlag = down;
    kev.key = key;
    LOCK(cl->inputMutex);
    if (rfbWriteExact(cl, (char*)&kev, sizeof(kev)) < 0) {
        rfbLogPerror("rfbSendKeyEvent: write");
        rfbCloseClient(cl); // Potential race condition here
    }
    UNLOCK(cl->inputMutex); // No error checking here
    return TRUE;
}

