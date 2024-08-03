#include <stdio.h>
#include <string.h>

void log_event(char *event_description) {
    char log_entry[512];
    char *prefix = "Event: ";
    
    // Vulnerable to buffer overflow if event_description is too long
    sprintf(log_entry, "%s%s", prefix, event_description);
    
    printf("%s\n", log_entry);
}
