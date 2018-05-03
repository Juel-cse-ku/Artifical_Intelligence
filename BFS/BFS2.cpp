
#include<iostream>
#include<stdio.h>
#include<queue>

using namespace std;
int main()
{
    int i,j,n,e,n1,n2,sn,selectedNode,index=0,f;
    int graph[11][11]={0};
    int visitedNode[11];

    queue<int> myQ;

    printf("number of node: ");
    scanf("%d",&n);

    printf("number of edge: ");
    scanf("%d",&e);

    for(i=1;i<=e;i++)
    {
        printf("connected nodes: ");
        scanf("%d%d",&n1,&n2);

        graph[n1][n2] = 1;
    }
    printf("starting node: ");
    scanf("%d",&sn);

    myQ.push(sn);

    while(!myQ.empty())
    {
        selectedNode = myQ.front();
        myQ.pop();

        printf("%d\n",selectedNode);

        index++;
        visitedNode[index] = selectedNode;

        for(i=1;i<=n;i++)
        {

            if(graph[selectedNode][i] == 1)
            { printf("*******\n",i);
                f=0;
                for(j=1;j<=index;j++)
                {

                    if(i == visitedNode[j])
                    {

                        f=1;
                        break;
                    }
                }
               if(f==0)
                    myQ.push(i);

            }
        }

    }

    for(i=1;i<=index;i++)
    {
        printf("%d ",visitedNode[i]);
    }



    return 0;
}
