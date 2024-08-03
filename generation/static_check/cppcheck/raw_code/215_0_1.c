static rfbBool pointAdjustAndValidate(int32_t *coordX, int32_t *coordY, rfbClientPtr cl) {
    int32_t x = Swap32IfLE(*coordX);
    int32_t y = Swap32IfLE(*coordY);

    if (x < 0 || y < 0) return FALSE;

    if (x > INT32_MAX - cl->screen->offsetX) return FALSE;
    if (y > INT32_MAX - cl->screen->offsetY) return FALSE;

    x += cl->screen->offsetX;
    y += cl->screen->offsetY;

    if (x > cl->screen->viewportWidth) return FALSE;
    if (y > cl->screen->viewportHeight) return FALSE;

    *coordX = x;
    *coordY = y;

    return TRUE;
}

