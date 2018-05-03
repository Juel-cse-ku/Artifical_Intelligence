#include<iostream>
#include<stdio.h>
#include<queue>

using namespace std;
int main()
{
    int i,j,n,e,n1,n2,sn,gn[44],sNode,ngn,index=0,f,c;
    int graph[44][44]={0};
    int vNodes[44];

    queue<int> myQueue;

    printf("number of nodes: ");
    scanf("%d",&n);

    printf("number of edges: ");
    scanf("%d",&e);

    for(i=1;i<=e;i++)
    {
        printf("connected nodes: ");
        scanf("%d%d",&n1,&n2);

        printf("path cost: ");
        scanf("%d",&c);

        graph[n1][n2] = c;
    }
    printf("starting node: ");
    scanf("%d",&sn);

    printf("number of goal node: ");
    scanf("%d",&ngn);
    for(i=1;i<=ngn;i++)
    {
        printf("goal %d: ",i);
        scanf("%d",&gn[i]);
    }




    //OUTPUT GRAPH
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for(i=1;i<=ngn;i++)
    {
        printf("%d ",gn[i]);

    }
    printf("\n");
    /********/

    myQueue.push(sn);

    while(!myQueue.empty())
    {
        sNode = myQueue.front();
        myQueue.pop();

        printf("%d ",sNode);

        index++;
        vNodes[index] = sNode;

        for(i=1;i<=n;i++)
        {
            if(graph[sNode][i] != 0)
            {
                f=0;
                for(j=1;j<=index;j++)
                {
                    if(i == vNodes[j])
                    {

                        f=1;
                        break;
                    }
                }
               if(f==0)
                    myQueue.push(i);

            }
        }

    }








    return 0;
}
