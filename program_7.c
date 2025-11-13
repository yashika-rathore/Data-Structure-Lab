#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define ALPHABET 26
struct Trie {
    struct Trie *child[ALPHABET];
    int isEnd;
};
struct Trie* newNode() {
    struct Trie *node = (struct Trie*)malloc(sizeof(struct Trie));
    node->isEnd = 0;
    for (int i = 0; i < ALPHABET; i++)
        node->child[i] = NULL;
    return node;
}
void insert(struct Trie *root, char *word) {
    struct Trie *temp = root;
    for (int i = 0; word[i]; i++) {
        int index = tolower(word[i]) - 'a';
        if (index < 0 || index >= ALPHABET) continue; 
        if (temp->child[index] == NULL)
            temp->child[index] = newNode();
        temp = temp->child[index];
    }
    temp->isEnd = 1;
}
int search(struct Trie *root, char *word) {
    struct Trie *temp = root;
    for (int i = 0; word[i]; i++) {
        int index = tolower(word[i]) - 'a';
        if (index < 0 || index >= ALPHABET) continue;
        if (temp->child[index] == NULL)
            return 0;
        temp = temp->child[index];
    }
    return temp->isEnd;
}
int main() {
    struct Trie *root = newNode();
    FILE *fp;
    char word[50];
    int choice;
    char *keys[] = {"and","bat","ball","book","cot","cotton",
                    "internet","interview","joy","job",
                    "king","lion","man","mango","manage"};
    int n = sizeof(keys)/sizeof(keys[0]);
    do {
        printf("\n========== TRIE MENU ==========\n");
        printf("1. Read keys from file and search\n");
        printf("2. Read keys from array and search\n");
        printf("3. Build from array and search words in file\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                fp = fopen("keys.txt", "r");
                if (!fp) {
                    printf("File not found!\n");
                    break;
                }
                while (fscanf(fp, "%s", word) != EOF)
                    insert(root, word);
                fclose(fp);

                printf("Enter word to search: ");
                scanf("%s", word);
                if (search(root, word))
                    printf("'%s' FOUND (from file)\n", word);
                else
                    printf("'%s' NOT found\n", word);
                break;
            case 2:
                for (int i = 0; i < n; i++)
                    insert(root, keys[i]);

                printf("Enter word to search: ");
                scanf("%s", word);
                if (search(root, word))
                    printf("'%s' FOUND (from array)\n", word);
                else
                    printf("'%s' NOT found\n", word);
                break;
            case 3:
                for (int i = 0; i < n; i++)
                    insert(root, keys[i]);

                fp = fopen("keys.txt", "r");
                if (!fp) {
                    printf("File not found!\n");
                    break;
                }
                printf("\nChecking words from file...\n");
                while (fscanf(fp, "%s", word) != EOF) {
                    if (search(root, word))
                        printf("%s FOUND\n", word);
                    else
                        printf("%s NOT found\n", word);
                }
                fclose(fp);
                break;
            case 4:
                printf("Exiting program... Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 4);
    return 0;
}
