typedef struct {
    int sensor_id;
    float temperature;
    float humidity;
} SensorData;

void log_sensor_data(SensorData *sensor_array, int sensor_array_size, int offset, FILE* file) {
    int i;
    float *temp_ptr;
    // Potential buffer overflow if offset is improperly calculated or sensor_array_size is too large
    for (i = 0; i < sensor_array_size; i++) {
        temp_ptr = (float*)((char*)&sensor_array[i] + offset);
        fprintf(file, "Sensor %d: Temperature: %.2f\n", sensor_array[i].sensor_id, *temp_ptr);
    }
}