void logSensorData(char *sensorData, uint32_t dataLength) {
    char logEntry[512];
    // Vulnerability: dataLength may exceed 512
    strncpy(logEntry, sensorData, dataLength); // Risk of buffer overflow
    logEntry[dataLength] = '\0'; // Potential out-of-bounds write
    printf("Sensor data logged: %s\n", logEntry);
}
