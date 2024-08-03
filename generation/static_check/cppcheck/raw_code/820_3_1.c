#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DETAILS_LENGTH 100

typedef struct {
    char name[50];
    char email[50];
} UserDetails;

void read_user_details(int client_sock) {
    UserDetails user;
    int bytes;

    // Vulnerable as it does not check for the sum of lengths of name and email against MAX_DETAILS_LENGTH
    bytes = recv(client_sock, &user, sizeof(UserDetails) + 20, 0); // Reading more bytes than the structure can hold
    if (bytes <= 0) {
        perror("Failed to read user details");
        exit(EXIT_FAILURE);
    }
    printf("User Name: %s\n", user.name);
    printf("User Email: %s\n", user.email);
}