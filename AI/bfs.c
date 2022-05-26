#include <stdio.h>
#define MAX 5


struct QUEUE{
    int arr[5];
    int rear;
    int front;
};

void insert(struct QUEUE* q,int i )
{
    (q->rear)++;
    (q->arr[q->rear])=i;
}

int delete(struct QUEUE* q)
{
    int a;
    (q->front)++;
     a = q->arr[q->front];
     return a;
}

void display(struct QUEUE* q)
{
    int i;
    for(i=(q->front)+1;i<=(q->rear);i++)
    {
        printf("%d",q->arr[i]);
    }
}

int isempty(struct QUEUE* Q)
{
    if(Q->front==Q->rear) return 1;
    else return 0;
}

void bfs(int graph[5][5],int i)
{
    int j,start;
    struct QUEUE q;
    q.front=-1;
    q.rear=-1;
    int visited[]={0,0,0,0,0};
    printf("%d",i);
    visited[i]=1;
    insert(&q,i);
    while(!isempty(&q))
    {
        start = delete(&q);
        for(j=0;j<5;j++)
        {
            if(graph[start][j]==1 && visited[j]==0)
            {
                printf("%d",j);
                visited[j]=1;
                insert(&q,j);
            }
        }
    }
}

void main()
{   
    int i =0,j,start;
    int graph[5][5] = {
        {0,1,1,0,0},
        {1,0,1,0,0},
        {1,0,0,1,1},
        {0,1,1,0,1},
        {0,0,1,1,0},
    };

    bfs(graph,i);
}