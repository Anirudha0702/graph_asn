// 0 1 1 0 0 0
// 1 0 1 1 0 0 
// 1 1 0 0 1 0
// 0 1 0 0 1 1 
// 0 0 1 1 0 1
// 0 0 0 1 1 0

#include<stdio.h>
#define MAX 100
int main(){
    int front=0,rear=0;
    int no_of_vertex=6;
    int starting_vertex=2;
    char vertex_name[]={'A','B','C','D','E','F'};
    int queue[MAX];
    int visited[6]={0};
    int adj_mat[6][6]={
        {0,1,1,0,0,0},
        {1,0,1,1,0,0},
        {1,1,0,0,1,0},
        {0,1,0,0,1,1},
        {0,0,1,1,0,1},
        {0,0,0,1,1,0}
    };
    visited[starting_vertex]=1;
    queue[rear++]=starting_vertex;
    printf("Visited vertex(in order): ");
    while(front!=rear){
        int current_vertex=queue[front++];
        printf("%c ",vertex_name[current_vertex]);
        for (int i = 0; i<no_of_vertex; i++)
        {
            if(!visited[i] && adj_mat[current_vertex][i]){
                queue[rear++]=i;
                visited[i]=1;
            }
        }
    }
    

    return 0;
}