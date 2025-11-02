#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Employee {
    char name[50];
    int salary;
    struct Employee* left;
    struct Employee* right;
} Employee;

// Function to create a new employee node
Employee* createEmployee(char* name, int salary) {
    Employee* newEmp = (Employee*)malloc(sizeof(Employee));
    strcpy(newEmp->name, name);
    newEmp->salary = salary;
    newEmp->left = newEmp->right = NULL;
    return newEmp;
}

// Insert employee into BST based on salary
Employee* insert(Employee* root, char* name, int salary) {
    if (root == NULL) {
        return createEmployee(name, salary);
    }
    if (salary < root->salary) {
        root->left = insert(root->left, name, salary);
    } else {
        root->right = insert(root->right, name, salary);
    }
    return root;
}

// Inorder traversal to display employees sorted by salary
void inorder(Employee* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("Name: %s, Salary: %d\n", root->name, root->salary);
        inorder(root->right);
    }
}

// Find employee with minimum salary (leftmost node)
Employee* findMin(Employee* root) {
    Employee* current = root;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Find employee with maximum salary (rightmost node)
Employee* findMax(Employee* root) {
    Employee* current = root;
    while (current && current->right != NULL) {
        current = current->right;
    }
    return current;
}

// Calculate total monthly expenses by summing all salaries in BST
int totalSalary(Employee* root) {
    if (root == NULL) return 0;
    return root->salary + totalSalary(root->left) + totalSalary(root->right);
}

int main() {
    Employee* root = NULL;
    int choice;
    char name[50];
    int salary;

    while (1) {
        printf("\n--- Employee Database Menu ---\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees by Salary\n");
        printf("3. Display Employee(s) with Minimum Salary\n");
        printf("4. Display Employee(s) with Maximum Salary\n");
        printf("5. Display Total Monthly Salary Expense\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter employee name: ");
                scanf(" %s", name);
                printf("Enter employee salary: ");
                scanf("%d", &salary);
                root = insert(root, name, salary);
                printf("Employee added successfully.\n");
                break;

            case 2:
                printf("\nEmployees sorted by salary:\n");
                inorder(root);
                break;

            case 3: {
                Employee* minEmp = findMin(root);
                if (minEmp)
                    printf("Employee with minimum salary: %s, Salary: %d\n", minEmp->name, minEmp->salary);
                else
                    printf("No employees in database.\n");
                break;
            }

            case 4: {
                Employee* maxEmp = findMax(root);
                if (maxEmp)
                    printf("Employee with maximum salary: %s, Salary: %d\n", maxEmp->name, maxEmp->salary);
                else
                    printf("No employees in database.\n");
                break;
            }

            case 5:
                printf("Total monthly salary expense: %d\n", totalSalary(root));
                break;

            case 6:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
