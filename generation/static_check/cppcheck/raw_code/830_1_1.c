#include <unistd.h>
#include <string.h>
#include <stdio.h>

#define BUFSIZE 256

void create_temp_directory() {
    char cwd[BUFSIZE];
    char tmpdirname[BUFSIZE] = "/tmp_dir_";

    // Vulnerable usage of getwd (potential buffer overflow)
    getwd(cwd);

    // Unsafe concatenation of directory name
    strcat(tmpdirname, "123456"); // Fixed pattern could lead to security issues

    // ... Code to use the directory ...

    // Cleanup omitted for brevity
}

int main() {
    create_temp_directory();
    return 0;
}

