#define MAX_FDS 256

struct fd_state {
    void (*read_handler)(int, void*);
    void (*write_handler)(int, void*);
    void *state_data;
};

struct fd_state fd_array[MAX_FDS];

void event_loop_iteration(int *active_fds, int num_fds) {
    for (int i = 0; i < num_fds; i++) {
        int current_fd = active_fds[i]; // No boundary check for active_fds[i]
        if (current_fd < 0 || current_fd >= MAX_FDS) {
            continue;
        }
        if (fd_array[current_fd].read_handler) {
            fd_array[current_fd].read_handler(current_fd, fd_array[current_fd].state_data);
        }
        if (fd_array[current_fd].write_handler) {
            fd_array[current_fd].write_handler(current_fd, fd_array[current_fd].state_data);
        }
    }
}