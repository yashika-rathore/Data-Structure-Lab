#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char song[50];
    struct Node *next;
};
struct Node *head = NULL;

void insertSong(char songName[]) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    strcpy(newNode->song, songName);
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct Node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
    printf("Song '%s' inserted into playlist.\n", songName);
}
void deleteSong(char songName[]) {
    if (head == NULL) {
        printf("Playlist is empty.\n");
        return;
    }
    struct Node *temp = head, *prev = NULL;
    do {
        if (strcmp(temp->song, songName) == 0) {
            if (temp == head) {
                struct Node *last = head;
                while (last->next != head) last = last->next;
                if (head == head->next) { // only one song
                    free(head);
                    head = NULL;
                } else {
                    last->next = head->next;
                    struct Node *del = head;
                    head = head->next;
                    free(del);
                }
            } else {
                prev->next = temp->next;
                free(temp);
            }
            printf("Song '%s' deleted from playlist.\n", songName);
            return;
        }
        prev = temp;
        temp = temp->next;
    } while (temp != head);
    printf("Song '%s' not found in playlist.\n", songName);
}
void playSongs() {
    if (head == NULL) {
        printf("Playlist is empty.\n");
        return;
    }
    struct Node *temp = head;
    printf("Playing songs in playlist:\n");
    do {
        printf("%s -> ", temp->song);
        temp = temp->next;
    } while (temp != head);
    printf("(back to start)\n");
}
void searchSong(char songName[]) {
    if (head == NULL) {
        printf("Playlist is empty.\n");
        return;
    }
    struct Node *temp = head;
    int found = 0;
    do {
        if (strcmp(temp->song, songName) == 0) {
            printf("Song '%s' found in playlist.\n", songName);
            found = 1;
            break;
        }
        temp = temp->next;
    } while (temp != head);
    if (!found) printf("Song '%s' not found.\n", songName);
}
void displayPlaylist() {
    if (head == NULL) {
        printf("Playlist is empty.\n");
        return;
    }
    struct Node *temp = head;
    printf("Playlist: ");
    do {
        printf("%s -> ", temp->song);
        temp = temp->next;
    } while (temp != head);
    printf("(back to start)\n");
}
void countSongs() {
    if (head == NULL) {
        printf("Playlist is empty.\n");
        return;
    }
    int count = 0;
    struct Node *temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    printf("Total songs in playlist: %d\n", count);
}
int main() {
    int choice;
    char song[50];
    do
    {
        printf("\n--- Music Playlist Menu ---\n");
        printf("1. Insert a Song\n");
        printf("2. Delete a Song\n");
        printf("3. Play Songs\n");
        printf("4. Search for a Song\n");
        printf("5. Display Playlist\n");
        printf("6. Count Songs\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                printf("Enter song name: ");
                gets(song);
                insertSong(song);
                break;
            case 2:
                printf("Enter song name to delete: ");
                gets(song);
                deleteSong(song);
                break;
            case 3:
                playSongs();
                break;
            case 4:
                printf("Enter song name to search: ");
                gets(song);
                searchSong(song);
                break;
            case 5:
                displayPlaylist();
                break;
            case 6:
                countSongs();
                break;
            case 7:
                return 0;
                printf("Exiting playlist.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (1);
    return 0;
}