static int networkDataReceive() {
    char dataBuffer[BUFFER_SIZE];
    int recvLen = customReceive(dataBuffer, DATA_MAX); // Vulnerable: DATA_MAX > BUFFER_SIZE
    if (recvLen < 0) {
        handle_error();
        return -1;
    }
    send_response(dataBuffer, recvLen); // Potential buffer overflow
    return 0;
}

