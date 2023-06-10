#include<stdio.h>
#include<stdbool.h> 
#define INF 9999999
#define NO_OF_VERTICES 7
int graph[NO_OF_VERTICES][NO_OF_VERTICES] = {
        {0, 10, 0, 0, 0, 5, 30},
        {10, 0, 20, 0, 0, 0, 0},
        {20, 0, 14, 12, 15, 25, 0},
        {0, 0, 12, 0, 11, 0, 0},
        {0, 0, 15, 11, 0, 9, 0},
        {5, 0, 25, 0, 9, 0, 6},
        {30, 0, 0, 0, 0, 6, 0}
    };
int main() {
  int no_of_edge;
  int min_cost=0;
  int visited_vertex[NO_OF_VERTICES];
  for(int i=0;i<NO_OF_VERTICES;++i){
    visited_vertex[i]=false;
  }
  no_of_edge = 0;
  visited_vertex[0] = true;
  int x,y;  
  printf("Edge : Weight\n");
  while (no_of_edge < NO_OF_VERTICES- 1) {
    int min = INF;
    x = 0;
    y = 0;
    for (int i = 0; i < NO_OF_VERTICES; i++) {
      if (visited_vertex[i]){
        for (int j = 0; j < NO_OF_VERTICES; j++) {
          if (!visited_vertex[j] && graph[i][j]) {  
            if (min > graph[i][j]) {
              min = graph[i][j];
              x = i;
              y = j;
            }
          }
        }
      }
    }
    printf("%d - %d : %d\n", x, y, graph[x][y]);
    min_cost+=graph[x][y];
    visited_vertex[y] = true;
    no_of_edge++;
  }
  printf("minimum cost is  %d ",min_cost);
  return 0;
}