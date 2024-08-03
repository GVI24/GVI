#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct component {
    char *id;
    struct component **children;
    int num_children;
} Component;

void render_component(Component *comp) {
    if (!comp) return;

    // Unchecked recursion may cause stack overflow
    for (int i = 0; i < comp->num_children; i++) {
        render_component(comp->children[i]);
    }
    // Memory leak: strdup without free
    char *id_copy = strdup(comp->id);
    printf("Component ID: %s\n", id_copy);
    // Missing free(id_copy);
}

int main() {
    // Setup components and call render_component...
    return 0;
}