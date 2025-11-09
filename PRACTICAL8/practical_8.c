/* AIM: write a program to implement Kruskal's Algorithm in order to find the minimum spanning Tree (MST) of a Connected ,Weighted and Undirected Graph*/

#include <stdio.h>

#define MAX 30

int parent[MAX];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void union_set(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

int main() {
    int n, e;
    int u[50], v[50], w[50];
    int i, j, total = 0, count = 0, temp;

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v weight):\n");
    for (i = 0; i < e; i++)
        scanf("%d%d%d", &u[i], &v[i], &w[i]);

    for (i = 0; i < n; i++)
        parent[i] = i;

    for (i = 0; i < e - 1; i++) {
        for (j = 0; j < e - i - 1; j++) {
            if (w[j] > w[j + 1]) {
                temp = w[j];
                w[j] = w[j + 1];
                w[j + 1] = temp;

                temp = u[j];
                u[j] = u[j + 1];
                u[j + 1] = temp;

                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }

    printf("\nEdges in Minimum Spanning Tree:\n");

    for (i = 0; i < e; i++) {
        int a = find(u[i]);
        int b = find(v[i]);

        if (a != b) {
            printf("%d - %d  weight: %d\n", u[i], v[i], w[i]);
            union_set(a, b);
            total += w[i];
            count++;
        }

        if (count == n - 1)
            break;
    }

    printf("\nTotal cost of Minimum Spanning Tree = %d\n", total);

    return 0;
}

/*Output:
Enter number of vertices: 4
Enter number of edges: 5
Enter edges (u v weight):
0 1 10
0 2 6
0 3 5
1 3 15
2 3 4

Edges in Minimum Spanning Tree:
2 - 3  weight: 4
0 - 3  weight: 5
0 - 1  weight: 10

Total cost of Minimum Spanning Tree = 19



*/