#include <stdio.h>

#define MAX_VERTICES 100

int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES]={{0, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0},
        {1, 1, 0, 1, 0, 0},
        {0, 0, 1, 0, 1, 1},
        {0, 0, 0, 1, 0, 1},
        {0, 0, 0, 1, 1, 0}};

void createGraph(int numVertices) {
    int i, j;
    int numEdges;
    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);
    //set all to zeo as there is no edges
    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            adjacencyMatrix[i][j] = 0;
        }
    }
    // set 1 if there is edge 
    for (i = 0; i < numEdges; i++) {
        printf("Enter the end vertices of edge %d:  ",i);
        int vertex1, vertex2;
        scanf("%d %d", &vertex1, &vertex2);
        adjacencyMatrix[vertex1][vertex2] = 1;
        adjacencyMatrix[vertex2][vertex1] = 1;
    }
}
void printAdjacencyList(int num_of_vertices){
    for(int i=0;i<num_of_vertices;++i){
        printf("%d:[ ",i+1);
        for(int j=0;j<num_of_vertices;++j){
            if(adjacencyMatrix[i][j]==1){
                printf("%d,",j+1);
            }
        }
        printf("]\n");
    }
}
int main() {
    int numVertices;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    // createGraph(numVertices);
    printAdjacencyList(numVertices);

    return 0;
}
