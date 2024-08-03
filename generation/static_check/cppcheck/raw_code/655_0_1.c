#include <time.h>
#include <limits.h>

typedef struct {
    time_t start_secs;
} timer_data;

void update_timer(timer_data *timer, unsigned int elapsed_ms) {
    unsigned int timer_ticks = elapsed_ms;
    if (timer == NULL) {
        return;
    }

    time_t now_secs = timer->start_secs + timer_ticks / 1000;
    while (now_secs < time(NULL) - 30) {
        timer_ticks += UINT_MAX/2;  // Vulnerable to integer overflow
        now_secs = timer->start_secs + timer_ticks / 1000;
    }
    // ... (additional logic)
}