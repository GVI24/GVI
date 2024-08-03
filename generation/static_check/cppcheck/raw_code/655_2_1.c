#include <stdint.h>

typedef struct {
    uint32_t bytes_sent;
    uint32_t bytes_received;
} traffic_counter;

void add_traffic(traffic_counter *counter, uint32_t sent, uint32_t received) {
    if (counter == NULL) {
        return;
    }

    counter->bytes_sent += sent;         // Vulnerable to integer overflow
    counter->bytes_received += received; // Vulnerable to integer overflow

    // ... (additional logic)
}