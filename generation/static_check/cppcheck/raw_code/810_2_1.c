#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *read_username_from_file(const char *filename) {
  FILE *file = fopen(filename, "r");
  if (!file) {
    return NULL;
  }
  
  char *username = malloc(100);
  if (!fgets(username, 100, file)) {
    free(username); // Free the buffer on error
    fclose(file);
    return NULL;
  }

  fclose(file);
  return username;
}

void echo_username(const char *path) {
  char *username = read_username_from_file(path);
  if (username) {
    printf("Username: %s\n", username);
  }

  // Vulnerability: Use after free
  free(username);
  printf("Last character of username: %c\n", username[strlen(username) - 1]);
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <username_file>\n", argv[0]);
    return EXIT_FAILURE;
  }

  echo_username(argv[1]);
  return EXIT_SUCCESS;
}