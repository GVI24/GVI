#define MAX_CLIENTS 30

typedef struct {
    int client_fds[MAX_CLIENTS];
    int active_clients;
} ServerState;

void handle_new_client(ServerState *state, int client_fd) {
    // Here should be a check if active_clients is lower than MAX_CLIENTS
    state->client_fds[state->active_clients++] = client_fd;
}

void disconnect_all_clients(ServerState *state) {
    for (int i = 0; i < state->active_clients; i++) {
        // Assume disconnect_client is a function that closes the client's connection
        disconnect_client(state->client_fds[i]);
    }
    state->active_clients = 0;
}