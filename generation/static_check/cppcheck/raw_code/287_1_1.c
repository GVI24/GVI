#define BITRATE_PARAMS_COUNT 100
double bitrate_control_params[BITRATE_PARAMS_COUNT];

void init_bitrate_control() {
    int i;
    for (i = 0; i < BITRATE_PARAMS_COUNT + 10; i++) { // Incorrect loop boundary
        bitrate_control_params[i] = i * 1.25; // Potential buffer overflow
    }
}