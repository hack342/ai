#include <iostream>
using namespace std;

struct queue{
    int data[5];
    int front;
    int rear;
};

int graph[5][5]={
    {0,1,1,0,0},
    {1,0,1,1,0},
    {1,1,0,0,1},
    {0,1,0,0,1},
    {0,0,1,1,0}
    };

int visited[5]={0,0,0,0,0};

void insert(int i,struct queue* q)
{
    q->rear++;
    q->data[q->rear]=i;
}

int pop(struct queue* q)
{
    q->front++;
    return q->data[q->front];
}

void bfs(int i)
{
    int start;
    int j;
    struct queue q;
    q.front=-1;
    q.rear=-1;
    cout<<i;
    visited[i]=1;
    insert(i,&q);
    while(q.front!=q.rear)
    {
        start=pop(&q);
        for(j=0;j<5;j++)
        {
            if(graph[start][j]==1 && visited[j]==0)
            {
               cout<<j;
               visited[j]=1;
               insert(j,&q);
               i=j; 
            }
        }
    }

}


void dfs(int i)
{
    int j;
    static int dfs_visited[5]={0,0,0,0,0};
    cout<<i;
    dfs_visited[i]=1;
    for(j=0;j<5;j++)
    {
        if(graph[i][j]==1 && dfs_visited[j]==0 )
        {
            dfs(j);
     
        }
    }
}

int main()
{
    int i,choice;
    cout<<"Enter Where to start";
    cin>>i;
    cout<<"1.BFS"<<endl<<"2.DFS"<<endl<<"Enter Your choice";
    cin>>choice;
    switch(choice)
    {
        case 1:
            bfs(i);
            break;
        case 2:
            dfs(i);
            break;
        default:
            cout<<"Enter valid choice"<<endl;
    }
    return 0;
}