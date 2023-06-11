#include <stdio.h>
#define V 5
#define INF 99999

void print_matrix(int matrix[][V]);

// Implementing floyd warshall algorithm
void floyd_warshall(int graph[][V]) {
  int matrix[V][V], i, j, k;

  for (i = 0; i < V; i++)
    for (j = 0; j < V; j++)
      matrix[i][j] = graph[i][j];

  // Adding vertices individually
  for (k = 0; k < V; k++) {
    for (i = 0; i < V; i++) {
      for (j = 0; j < V; j++) {
        if (matrix[i][k] + matrix[k][j] < matrix[i][j])
          matrix[i][j] = matrix[i][k] + matrix[k][j];
      }
    }
  }
  print_matrix(matrix);
}

void print_matrix(int matrix[][V]) {
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      if (matrix[i][j] == INF)
        printf("%4s", "INF");
      else
        printf("%4d", matrix[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int graph[V][V] = 
  {{0, 4, 3, 4, 3},
        {4, 0, 2, 3, INF},
        {3, 2, 0, INF, 3},
        {4, 3, INF, 0, 2},
        {3, INF, 3, 2, 0}};
  floyd_warshall(graph);
}