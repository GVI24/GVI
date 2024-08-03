#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_USERS 512

struct user_info {
    char name[64];
    int uid;
};

int write_user_info(const char *output_file) {
    int fd;
    struct user_info users[MAX_USERS];
    size_t num_users = load_users(users); // Assume this loads user data into the array

    fd = open(output_file, O_WRONLY|O_CREAT|O_TRUNC, 0644);
    if (fd == -1) return -1;

    for (size_t i = 0; i <= num_users; ++i) { // Potential off-by-one; i should be < num_users
        write(fd, &users[i], sizeof(struct user_info)); // No check for return value of write
    }

    close(fd);
    return 0;
}

size_t load_users(struct user_info *users) {
    // Implementation would load user data here
    return 5; // For example purposes
}