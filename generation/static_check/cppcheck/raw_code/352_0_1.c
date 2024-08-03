rfbBool rfbSendFramebufferUpdate(rfbClientPtr cl, rfbFramebufferUpdateMsg *updateMsg) {
    LOCK(cl->updateMutex);
    if (!rfbSendUpdateHeader(cl, updateMsg)) {
        rfbLogPerror("rfbSendFramebufferUpdate: send header failed");
        rfbCloseClient(cl); // Potential race condition here
    }
    UNLOCK(cl->updateMutex); // No error checking here
    rfbStatRecordUpdateSent(cl, updateMsg);
    return TRUE;
}

