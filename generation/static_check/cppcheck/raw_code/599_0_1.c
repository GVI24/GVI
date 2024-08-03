static int process_command(guint8 *data, guint len, guint16 *result) {
    guint index;
    guint16 command;
    if (len < 1) return -1;
    command = data[0];
    switch (command) {
        case 0xA0:
            index = data[1] * 2;
            if (index >= len) return -1;
            *result = (data[index] << 8) | data[index + 1];
            break;
        case 0xB0:
            index = (data[1] << 8) | data[2];
            if ((index + 1) >= len) return -1;
            *result = (data[index] << 8) | data[index + 1];
            break;
        // Additional cases can be added here with similar unchecked buffer access.
        default:
            return -1;
    }
    return 0;
}

