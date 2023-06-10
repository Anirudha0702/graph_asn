#include<stdio.h>
typedef struct EDGE{
    int start_vertex;
    int end_vertex;
    int weight;
} Edge;
int parent_list[100];

int find(int no_of_vertices,int a){
    if(parent_list[a]==a)return a;
    return find(no_of_vertices,parent_list[a]);
}
void _union(int no_of_vertices,int a,int b){
    int root_of_a=find(no_of_vertices,a);
    int root_of_b=find(no_of_vertices,b);
    if(root_of_a==root_of_b)return;
    else{
        parent_list[root_of_b]=root_of_a;
    }
}
int will_not_create_cycle(int no_of_vertices,Edge edge){
    int root_of_start_vertex=find(no_of_vertices,edge.start_vertex);
    int root_of_end_vertex=find(no_of_vertices,edge.end_vertex);
    if(root_of_start_vertex!=root_of_end_vertex){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    int no_of_vertex;
    
    printf("Enter no of vertices:   ");
    scanf("%d",&no_of_vertex);
    int adj_mat[no_of_vertex][no_of_vertex];
    for(int i=0;i<no_of_vertex;++i){
        parent_list[i]=i;
    }
    Edge edges[100];
    Edge mst_edges[100];
    int edges_index=0;
    int mst_edges_index=0;
    int min_weight=0;

    printf("Enter adjacency matrix\n");
    for(int i=0;i<no_of_vertex;++i){
        for(int j=0;j<no_of_vertex;++j){
            scanf("%d",&adj_mat[i][j]);
        }
    }
    for(int i=0;i<no_of_vertex;++i){
        for(int j=0;j<no_of_vertex;++j){
            if(i<=j && adj_mat[i][j]!=0){
                edges[edges_index].start_vertex=i;
                edges[edges_index].end_vertex=j;
                edges[edges_index].weight=adj_mat[i][j];
                edges_index++;
            }
        }
    }
    /// sort edge array acording their edge.weight using bubble sort  method 
    for( int i=0;i<edges_index;++i){
        for(int j=0;j<edges_index-i-1;++j){
            if(edges[j+1].weight<edges[j].weight){
                Edge temp_edge=edges[j+1];
                edges[j+1]=edges[j];
                edges[j]=temp_edge;
            }
        }
    }
    //find MST 
    int count=1;
    for(int i=0;count<no_of_vertex;++i){
        if(will_not_create_cycle(no_of_vertex,edges[i])){
            _union(no_of_vertex,edges[i].start_vertex,edges[i].end_vertex);
            mst_edges[mst_edges_index++]=edges[i];
            min_weight+=edges[i].weight;
            count++;
        }
    }
    printf("minimum weight %d\n",min_weight);
    for(int i=0;i<no_of_vertex-1;++i){
        printf("%d. %d--%d  w:%d\n",i+1,edges[i].start_vertex,edges[i].end_vertex,edges[i].weight);
    }
    return 0;
}

// 0 12 20 0 10 10
// 12 0 9 0 0 0
// 20 9 0 3 0 0
// 0 0 3 0 30 5
// 10 0 0 30 0 20
// 10 0 0 5 20 0