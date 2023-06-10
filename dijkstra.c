#include<stdio.h>
#include <math.h>
#define INF 2147483647

int get_min_among_unvisited_vertex(int distance[],int all_vertices[],int no_of_vertex,int visited[]){
    int min_index;
    for(int i=0;i<no_of_vertex;++i){
        if(!visited[i]){
            min_index=i;
            break;
        }
    }
    for (int i = 0; i < no_of_vertex; i++)
    {
        if(!visited[i]   && distance[min_index]>distance[i]){
            min_index=i;
        }
    }
    
    return min_index;
}
int main(){
    int no_of_vertex=6;
    char vertex_name[6]={'P','Q','R','S','U','V'};
    int source_vertex=0;//P
    int copy_of_source_vertex=source_vertex;
    int path_index=0;
    int distance[6];
    int destination_vertex=2;//R
    int path[6];
    int came_from_vertex[no_of_vertex];
    int visited[no_of_vertex];
    int all_vertices[no_of_vertex];
    int cost_mat[6][6]={
        {0,10,0,6,12,0},
        {10,0,15,0,7,8},
        {0,15,25,20,20},
        {6,0,25,0,9,5},
        {12,7,20,9,0,0},
        {0,8,20,5,0,0}
    };
    for (int i = 0; i < 6; i++)
    {
        distance[i]=INF;
        visited[i]=0;
    }
    distance[source_vertex]=0;
    visited[0]=1;
    int minCost=INF;
    while(source_vertex!=destination_vertex){
        for(int i=0;i<no_of_vertex;++i){
            if(!visited[i] && distance[source_vertex]+cost_mat[source_vertex][i]<distance[i] && cost_mat[source_vertex][i]>0){
                distance[i]=distance[source_vertex]+cost_mat[source_vertex][i];
                came_from_vertex[i]=source_vertex;
            }
        }
        source_vertex=get_min_among_unvisited_vertex(distance,all_vertices,no_of_vertex,visited);
        visited[source_vertex]=1;
    }
    printf("\n minimum cost from vertex %c to %c is %d\n",vertex_name[copy_of_source_vertex],vertex_name[destination_vertex],distance[destination_vertex]);

    return 0;
}


