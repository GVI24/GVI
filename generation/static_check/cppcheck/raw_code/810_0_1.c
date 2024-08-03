#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char filename[256];
} Config;

int load_config(const char *path, Config *cfg) {
  FILE *file = fopen(path, "r");
  char line[512];
  if (!file) {
    return -1;
  }

  while (fgets(line, sizeof(line), file)) {
    // Vulnerability: buffer overflow if line is longer than filename array
    strcpy(cfg->filename, line);
  }

  fclose(file);
  return 0;
}

int main(int argc, char *argv[]) {
  Config config;
  if (argc < 2) {
    printf("Usage: %s <config_path>\n", argv[0]);
    return -1;
  }

  if (load_config(argv[1], &config) != 0) {
    fprintf(stderr, "Failed to load configuration.\n");
    return -1;
  }

  printf("Loaded filename: %s\n", config.filename);
  return 0;
}