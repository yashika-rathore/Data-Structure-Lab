#include <stdio.h>
#include <stdlib.h>
struct Node {
    int bill;
    struct Node* next;
};
struct Node* head = NULL;
// Function to insert a new bill at the end
void insertBill(int amount) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->bill = amount;
    newNode->next = NULL;

    if(head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Bill of %d added successfully!\n", amount);
}
// Function to display all bills
void displayBills() {
    if(head == NULL) {
        printf("\nNo bills recorded yet.\n");
        return;
    }
    printf("\nCoffee Shop Bills:\n");
    struct Node* temp = head;
    while(temp != NULL) {
        printf("%d ", temp->bill);
        temp = temp->next;
    }
    printf("\n");
}
// Function to calculate total sales
void totalSale() {
    int sum = 0;
    struct Node* temp = head;
    while(temp != NULL) {
        sum += temp->bill;
        temp = temp->next;
    }
    printf("\nTotal Sale of the Day = %d\n", sum);
}
// Function to find maximum and minimum bill
void maxMinBill() {
    if(head == NULL) {
        printf("\nNo bills recorded.\n");
        return;
    }
    int max = head->bill, min = head->bill;
    struct Node* temp = head->next;
    while(temp != NULL) {
        if(temp->bill > max) max = temp->bill;
        if(temp->bill < min) min = temp->bill;
        temp = temp->next;
    }
    printf("\nMaximum Bill = %d", max);
    printf("\nMinimum Bill = %d\n", min);
}
int main() {
    int choice, amount;
    do {
        printf("\n--- Coffee Shop Menu ---\n");
        printf("1. Insert a Bill\n");
        printf("2. Display All Bills\n");
        printf("3. Total Sale of the Day\n");
        printf("4. Maximum and Minimum Bill\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter bill amount: ");
                scanf("%d", &amount);
                insertBill(amount);
                break;
            case 2:
                displayBills();
                break;
            case 3:
                totalSale();
                break;
            case 4:
                maxMinBill();
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while(choice != 5);
    return 0;
}
