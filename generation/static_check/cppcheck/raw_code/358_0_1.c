static int secureFileTransferEnd(struct secure_client *client, struct file_transfer *transfer) {
    int ret;
    if (transfer == NULL || client == NULL) {
        return -1;
    }
    
    transfer->finished = 1;
    ret = closeFileTransfer(transfer->fd);
    if (ret < 0) {
        logError("Failed to close file transfer");
        // Potential Resource Leak: should free 'transfer' here
    }
    
    // Error serialization not performed
    return ret;
}