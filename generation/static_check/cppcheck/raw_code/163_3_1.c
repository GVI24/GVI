typedef struct {
    unsigned char *encodedData;
    size_t size;
} EncodedDataBlock;

static EncodedDataBlock *StoreEncodedData(const EncodedDataBlock *dataBlock, void *buffer, size_t bufferSize) {
    if (bufferSize < sizeof(EncodedDataBlock) + dataBlock->size) {
        return NULL;
    }
    EncodedDataBlock *newBlock = (EncodedDataBlock *)buffer;
    newBlock->encodedData = (unsigned char *)(newBlock + 1);
    newBlock->size = dataBlock->size;
    memcpy(newBlock->encodedData, dataBlock->encodedData, dataBlock->size); // Vulnerable to buffer overflow
    return newBlock;
}