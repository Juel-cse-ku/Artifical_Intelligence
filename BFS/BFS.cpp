#include<iostream>
#include<stdio.h>
#include<queue>

using namespace std;
int main()
{
    int i,j,k,n,e,n1,n2,sn,selectedNode,index=0,f;
    int graph[11][11]={0};
    int visited[11],path[11];
    queue<int> myQueue;


    printf("Number of node: ");
    scanf("%d",&n);

    printf("Number of edge: ");
    scanf("%d",&e);

    for(i=1;i<=e;i++)
    {
        printf("enter connected node: ");
        scanf("%d%d",&n1,&n2);

        graph[n1][n2]=1;
        //graph[n2][n1]=1;
    }


    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {

            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }

    printf("starting node: ");
    scanf("%d",&sn);

    myQueue.push(sn);

    while(!myQueue.empty())
    {

        selectedNode = myQueue.front();
        myQueue.pop();

        printf("%d ",selectedNode);
        index++;
        visited[index] = selectedNode;


printf("******\n");
        for(i=1;i<=index;i++)
        {
            printf("%d ",visited[i]);
        }
        printf("*******\n");


        for(i=1;i<=n;i++)
        {

            f=0;
            if(graph[selectedNode][i] !=0)
            {
                for(j=1;j<=index;j++)
                {

                    if(i == visited[j])
                    {

                        f=1;
                        break;
                    }

                }
            }

            if(graph[selectedNode][i]==1 && f==0 )
                    myQueue.push(i);


        }

    }






    return 0;
}
