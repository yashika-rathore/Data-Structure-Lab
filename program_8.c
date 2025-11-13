#include <stdio.h>
#include <stdlib.h>
#define MAX 20
int n;
int adj[MAX][MAX];
int visited[MAX];
void DFS_iterative(int start, int skip) {
    int stack[MAX], top = -1;
    stack[++top] = start;
    visited[start] = 1;
    while (top != -1) {
        int v = stack[top--];
        for (int i = 0; i < n; i++) {
            if (adj[v][i] == 1 && visited[i] == 0 && i != skip) {
                visited[i] = 1;
                stack[++top] = i;
            }
        }
    }
}
int isConnected(int skip) {
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    int start = -1;
    for (int i = 0; i < n; i++) {
        if (i != skip) {
            start = i;
            break;
        }
    }
    DFS_iterative(start, skip);
    for (int i = 0; i < n; i++) {
        if (i != skip && visited[i] == 0)
            return 0;
    }
    return 1;
}
int main() {
    printf("Enter number of nodes in network: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix of the network:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);
    printf("\n--- Single Node Failure Detection ---\n\n");
    for (int i = 0; i < n; i++) {
        if (isConnected(i))
            printf("After removing node %d: Network is still connected.\n", i);
        else
            printf("After removing node %d: Network becomes DISCONNECTED.\n", i);
    }
    return 0;
}
