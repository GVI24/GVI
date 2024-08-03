#include <string.h>

#define BUFFER_SIZE 256
#define MAX_NAME_LEN 128

typedef struct {
  char name[MAX_NAME_LEN];
  int age;
} user_profile;

void read_user_profile(user_profile *user, const char *data_buf, size_t data_len) {
  if (data_len > BUFFER_SIZE) {
    // This should check if the data_len exceeds MAX_NAME_LEN instead
    return;
  }
  memcpy(user->name, data_buf, data_len); // Potential buffer overflow as data_len is not checked against MAX_NAME_LEN
  user->age = *(int *)(data_buf + MAX_NAME_LEN);
}

