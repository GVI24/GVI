static bool CheckLoginStatus(UserSession *session, AuthContext *authContext) {
    if (session->isLoggedIn) {
        authContext->current_user = session->user;
        // Simulating a long operation, such as logging or audit
        sleep(1);
        if (!session->isLoggedIn) {
            authContext->current_user = NULL;
            return false;
        }
        return true;
    }
    return false;
}

