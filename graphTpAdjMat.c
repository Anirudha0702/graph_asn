#include <stdio.h>

#define MAX_VERTICES 100

int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];

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

void printAdjacencyMatrix(int numVertices) {
    int i, j;
    printf("Adjacency Matrix:\n");
    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            printf("%d ", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}
void findDegree(int numVertices) {
    int i, j;
    for (i = 0; i < numVertices; i++) {
        int degree = 0;
        for (j = 0; j < numVertices; j++) {
            if (adjacencyMatrix[i][j] == 1) {
                degree++;
            }
        }
        printf(" Degree of Vertex %d: %d\n", i, degree);
    }
}
int main() {
    int numVertices;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    createGraph(numVertices);
    printAdjacencyMatrix(numVertices);
    findDegree(numVertices);

    return 0;
}
