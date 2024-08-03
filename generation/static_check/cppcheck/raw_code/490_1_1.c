static int fetchData(int sock, char *data, size_t dataLen) {
    size_t totalRead = 0;
    ssize_t numRead;
    while (totalRead < dataLen) {
        numRead = recv(sock, data + totalRead, dataLen - totalRead, 0);
        if (numRead <= 0) {
            if (numRead == 0 || errno != EAGAIN)
                break;
        }
        totalRead += numRead; // Potential over-read if numRead is larger than expected
    }
    if (totalRead > dataLen) // Incorrect bounds check after the fact
        return -1;
    data[totalRead] = '\0'; // Assuming there's space for the null terminator
    return 0;
}

