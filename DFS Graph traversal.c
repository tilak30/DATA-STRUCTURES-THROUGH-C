#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int graph[MAX][MAX],visited[MAX];
int v;

void make_graph(){
    int i,j;
    printf("Enter no of edges: ");
    scanf("%d",&v);
    printf("Enter adjacency matrix values of a graph: ");
    for(i=0;i<v;i++)
        for(j=0;j<v;j++)
            scanf("%d",&graph[i][j]);
    for(i=0;i<v;i++){
        visited[i]=0;
    }
}

void graph_traversal(int vtx){
    printf("%d ",vtx);
    int i;
    visited[vtx]=1;
    for(i=0;i<v;i++)
        if(!visited[i] && graph[vtx][i]==1)
            graph_traversal(i);
}

int main()
{
    printf("*********************Welcome to Depth First Search*********************\n");
    make_graph();
    printf("Enter vertex from where u want to start traversal: ");
    int vtx;   scanf("%d",&vtx);
    printf("Elements traversed using DFS is as follows: ");
    graph_traversal(vtx);
    printf("\n");
    return 0;
}
