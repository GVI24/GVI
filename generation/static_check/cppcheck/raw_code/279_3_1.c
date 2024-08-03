#include <pthread.h>

// An example user session object
typedef struct {
    // Session details
} UserSession;

UserSession* current_session = NULL;

void initialize_user_session() {
    if (current_session == NULL) {
        // Assuming a single user session without protection against simultaneous access
        current_session = (UserSession*)malloc(sizeof(UserSession));
        // Omitted: Code to initialize the session
    }
}

UserSession* get_current_session() {
    initialize_user_session();
    return current_session;
}