pid_t createWorkerProcess(const char *workerPath, char *const argv[]) {
    pid_t pid;
    int numTries = 0;
    do {
        pid = fork();
        if (pid == 0) {
            // Child process
            execv(workerPath, argv);
            exit(1); // Should not reach here unless execv fails
        } else if (pid < 0) {
            // Fork failed, try again
            numTries++;
            if (numTries >= 5) {
                perror("createWorkerProcess: Fork failed\n");
                return -1;
            }
        }
    } while (pid < 0);
    return pid;
}