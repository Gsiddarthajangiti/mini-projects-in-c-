#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MSG_LEN 256

void chat() {
    char user1[MAX_MSG_LEN];
    char user2[MAX_MSG_LEN];
    
    printf("Simple Chat Application\n");
    printf("Type '/exit' to end the chat\n\n");
    
    while (1) {
        // User 1's turn
        printf("User 1: ");
        fgets(user1, MAX_MSG_LEN, stdin);
        strtok(user1, "\n"); // remove trailing newline
        
        if (strcmp(user1, "/exit") == 0) {
            printf("Chat ended by User 1.\n");
            break;
        }

        // User 2's turn
        printf("User 2: ");
        fgets(user2, MAX_MSG_LEN, stdin);
        strtok(user2, "\n"); // remove trailing newline
        
        if (strcmp(user2, "/exit") == 0) {
            printf("Chat ended by User 2.\n");
            break;
        }
    }
}

int main() {
    chat();
    return 0;
}

