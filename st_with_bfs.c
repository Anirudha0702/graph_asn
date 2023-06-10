#include<stdio.h>
#define V 6

void bfs(int adj_mat[V][V], int start_vertex) {
    int queue[V];
    int front = 0, rear = 0;
    int visited[V] = {0};

    visited[start_vertex] = 1;
    queue[rear++] = start_vertex;

    printf("BFS Traversal: ");

    while (front < rear) {
        int current_vertex = queue[front++];
        printf("%d ", current_vertex+1);

        for (int i = 0; i < V; i++) {
            if (adj_mat[current_vertex][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    int adj_mat[V][V] = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0},
        {1, 1, 0, 1, 0, 0},
        {0, 0, 1, 0, 1, 1},
        {0, 0, 0, 1, 0, 1},
        {0, 0, 0, 1, 1, 0}
    };
    int start_vertex = 0;

    bfs(adj_mat, start_vertex);

    return 0;
}
