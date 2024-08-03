#define MAX_PARTICIPANTS 100

typedef struct {
    int id;
    void (*event_handler)(int);
} participant_t;

participant_t participant_list[MAX_PARTICIPANTS];

void trigger_event(int *participant_ids, int count) {
    for (int i = 0; i < count; i++) {
        int id = participant_ids[i]; // No validation for participant_ids[i]
        if (id < 0 || id >= MAX_PARTICIPANTS) {
            continue;
        }
        if (participant_list[id].event_handler != NULL) {
            participant_list[id].event_handler(participant_list[id].id);
        }
    }
}