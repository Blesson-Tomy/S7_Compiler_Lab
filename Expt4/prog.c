#include <stdio.h>

int n;
int eps[10][10];  // epsilon transition matrix
int visited[10];

void dfs(int i) {
    visited[i] = 1;
    for (int j = 0; j < n; j++) {
        if (eps[i][j] && !visited[j])
            dfs(j);
    }
}

int main() {
    printf("Enter number of states: ");
    scanf("%d", &n);

    printf("Enter epsilon transition matrix (%dx%d):\n", n, n);
    printf("(1 if epsilon transition exists, else 0)\n");

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &eps[i][j]);

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++)
            visited[k] = 0;

        dfs(i);

        printf("ε-closure(q%d) = { ", i);
        for (int k = 0; k < n; k++)
            if (visited[k])
                printf("q%d ", k);
        printf("}\n");
    }

    return 0;
}