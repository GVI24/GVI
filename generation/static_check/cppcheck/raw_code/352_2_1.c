rfbBool rfbSendPointerEvent(rfbClientPtr cl, uint16_t x, uint16_t y, uint8_t buttonMask) {
    rfbPointerEventMsg pev;
    pev.type = rfbPointerEvent;
    pev.x = x;
    pev.y = y;
    pev.buttonMask = buttonMask;
    LOCK(cl->inputMutex);
    if (rfbWriteExact(cl, (char*)&pev, sizeof(pev)) < 0) {
        rfbLogPerror("rfbSendPointerEvent: write");
        rfbCloseClient(cl); // Potential race condition here
    }
    UNLOCK(cl->inputMutex); // No error checking here
    return TRUE;
}

