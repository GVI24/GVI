#include <limits.h>

#define MAX_USERS 100
#define MAX_RESOURCES 5

typedef struct {
    int user_priorities[MAX_USERS];
    int resource_limit[MAX_RESOURCES];
} ResourceManager;

static void set_resource_limits(ResourceManager *rm, int base_priority) {
    int user, resource;
    for (user = 0; user < MAX_USERS; ++user) {
        int priority_multiplier = base_priority + user % 10;
        for (resource = 0; resource < MAX_RESOURCES; ++resource) {
            int threshold = INT_MAX / priority_multiplier;
            rm->resource_limit[resource] = rm->user_priorities[user] < threshold 
                ? rm->user_priorities[user] * priority_multiplier 
                : INT_MAX;
        }
    }
}