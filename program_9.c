#include <stdio.h>
#include <stdlib.h>
#define MAX 20
typedef struct Node {
    int vertex;
    struct Node *next;
} Node;
Node *adjList[MAX];
int adj[MAX][MAX];
void addEdge(int u, int v) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = adjList[u];
    adjList[u] = newNode;
}
int detectCycleMatrix(int n, int adj[MAX][MAX]) {
    int visited[MAX], parent[MAX], stack[MAX], top;
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    for (int start = 0; start < n; start++) {
        if (!visited[start]) {
            top = -1;
            stack[++top] = start;
            parent[start] = -1;
            visited[start] = 1;
            while (top != -1) {
                int v = stack[top--];
                for (int i = 0; i < n; i++) {
                    if (adj[v][i]) {
                        if (!visited[i]) {
                            visited[i] = 1;
                            parent[i] = v;
                            stack[++top] = i;
                        } else if (parent[v] != i) {
                            return 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
int detectCycleList(int n) {
    int visited[MAX], parent[MAX], stack[MAX], top;
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    for (int start = 0; start < n; start++) {
        if (!visited[start]) {
            top = -1;
            stack[++top] = start;
            parent[start] = -1;
            visited[start] = 1;
            while (top != -1) {
                int v = stack[top--];
                Node *temp = adjList[v];
                while (temp) {
                    int i = temp->vertex;
                    if (!visited[i]) {
                        visited[i] = 1;
                        parent[i] = v;
                        stack[++top] = i;
                    } else if (parent[v] != i) {
                        return 1;
                    }
                    temp = temp->next;
                }
            }
        }
    }
    return 0;
}
void readGraphFromFile(int adj[MAX][MAX], int *n) {
    FILE *fp;
    fp = fopen("graph.txt", "r");
    if (fp == NULL) {
        printf("Error: Cannot open file.\n");
        exit(1);
    }
    fscanf(fp, "%d", n);
    for (int i = 0; i < *n; i++)
        for (int j = 0; j < *n; j++)
            fscanf(fp, "%d", &adj[i][j]);
    fclose(fp);
}
int main() {
    int n, choice;
    for (int i = 0; i < MAX; i++)
        adjList[i] = NULL;
    do {
        printf("\nCycle Detection in Graph\n");
        printf("1. Input from file\n");
        printf("2. Input as adjacency list\n");
        printf("3. Input as adjacency matrix\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                readGraphFromFile(adj, &n);
                if (detectCycleMatrix(n, adj))
                    printf("Cycle detected in the graph.\n");
                else
                    printf("No cycle detected in the graph.\n");
                break;
            }
            case 2: {
                printf("Enter number of vertices: ");
                scanf("%d", &n);
                int edges, u, v;
                printf("Enter number of edges: ");
                scanf("%d", &edges);
                for (int i = 0; i < edges; i++) {
                    printf("Enter edge %d (u v): ", i + 1);
                    scanf("%d %d", &u, &v);
                    addEdge(u, v);
                    addEdge(v, u);
                }
                if (detectCycleList(n))
                    printf("Cycle detected in the graph.\n");
                else
                    printf("No cycle detected in the graph.\n");
                break;
            }
            case 3: {
                printf("Enter number of vertices: ");
                scanf("%d", &n);
                printf("Enter adjacency matrix:\n");
                for (int i = 0; i < n; i++)
                    for (int j = 0; j < n; j++)
                        scanf("%d", &adj[i][j]);
                if (detectCycleMatrix(n, adj))
                    printf("Cycle detected in the graph.\n");
                else
                    printf("No cycle detected in the graph.\n");
                break;
            }
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (1);
    return 0;
}
