static rfbBool updateScreenRegion(uint16_t posX, uint16_t posY, uint16_t sizeX, uint16_t sizeY, rfbClientPtr cl) {
    int32_t x = Swap16IfLE(posX);
    int32_t y = Swap16IfLE(posY);
    int32_t width = Swap16IfLE(sizeX);
    int32_t height = Swap16IfLE(sizeY);

    x = (x < 0 ? 0 : x);
    y = (y < 0 ? 0 : y);

    if (width < 0 || height < 0 || width > cl->screen->width - x || height > cl->screen->height - y)
        return FALSE;

    cl->updateRegion.x = x;
    cl->updateRegion.y = y;
    cl->updateRegion.width = width;
    cl->updateRegion.height = height;

    return TRUE;
}

