static rfbBool refreshScreen(uint16_t startX, uint16_t startY, uint16_t endX, uint16_t endY, rfbClientPtr cl) {
    int32_t x0 = Swap16IfLE(startX);
    int32_t y0 = Swap16IfLE(startY);
    int32_t x1 = Swap16IfLE(endX);
    int32_t y1 = Swap16IfLE(endY);
    int32_t deltaX, deltaY;

    if (x0 < 0 || y0 < 0 || x1 < 0 || y1 < 0) return FALSE;

    deltaX = x1 - x0;
    deltaY = y1 - y0;

    if (deltaX < 0 || deltaY < 0 || deltaX > cl->screen->width || deltaY > cl->screen->height)
        return FALSE;

    cl->refreshRegion.x = x0;
    cl->refreshRegion.y = y0;
    cl->refreshRegion.width = deltaX;
    cl->refreshRegion.height = deltaY;

    return TRUE;
}