#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int arr[MAX][MAX];
int visited[MAX];
int queue[MAX],front=-1,rear=-1;
int v;

void built_graph(){
    printf("Enter no of vertices: ");
    scanf("%d",&v);
    printf("Enter values in adjacency matrix representation: ");
    int i,j;
    for(i=0;i<v;i++)
        for(j=0;j<v;j++)
            scanf("%d",&arr[i][j]);
}

void insert_queue(int d){
    if(rear==MAX-1)
        printf("Queue Overflow");
    else{
        if(front==-1)
            front=0;
        queue[++rear]=d;
    }
}

int Queue_is_Empty(){
    if(front==-1 || front>rear)
        return 1;
    else
        return 0;
}

int Pop_Queue(){
    if(front==-1 || front>rear){
        printf("Queue Underflow\n");
        exit(0);
    }
    return queue[front++];
}

void bfs(int vtx){
    insert_queue(vtx);
    visited[vtx]=1;
    printf("Visited node: ");
    while(!Queue_is_Empty()){
        vtx=Pop_Queue();
        printf("%d ",vtx);
        int i;
        for(i=0;i<v;i++){
            if(arr[vtx][i]==1 && visited[i]==0){
                insert_queue(i);
                visited[i]=1;
            }
        }
    }
    printf("\n");
}

void traverse_graph(){
    int i;
    for(i=0;i<v;i++)
        visited[i]=0;
    printf("Enter Start Vertex for Breadth First Search: ");
    scanf("%d",&i);
    bfs(i);
}

int main()
{
    printf("********************Welcome to bfs searching*********************\n\n");
    built_graph();
    traverse_graph();
    return 0;
}
