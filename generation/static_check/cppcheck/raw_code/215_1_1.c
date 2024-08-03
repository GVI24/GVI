static rfbBool bufferAllocate(uint16_t width, uint16_t height, rfbScreenInfoPtr screen) {
    int32_t bufWidth = Swap16IfLE(width);
    int32_t bufHeight = Swap16IfLE(height);
    int32_t size;

    if (bufWidth < 0 || bufHeight < 0) return FALSE;

    if (bufWidth > INT32_MAX / bufHeight) return FALSE;

    size = bufWidth * bufHeight * screen->depth;
    screen->frameBuffer = malloc(size);
    if (!screen->frameBuffer) return FALSE;

    return TRUE;
}

