#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int check(int temp[])
{
    int i,j;
    int countt =0;
    for(i=1;i<=7;i++)
    {
        for(j=i+1;j<=8;j++)
        {
            if(temp[i]==temp[j] || abs(temp[i]-temp[j]) == abs(i-j))
            {
                countt++;
            }
        }
    }
    return countt;
}
int main()
{
    srand(time(NULL));


    int i,j,m,n,k;
    int population[11][10]={0};
    int temp1[10]={0},temp2[10]={0},temp[10]={0};

    for(i=1;i<=10;i++)
    {
        for(j=1;j<=8;j++)
        {
            temp[j] = 1 + rand()%8;
            population[i][j] = temp[j];
        }
        population[i][9] = check(temp);
    }
    for(i=1;i<=10;i++)
    {
        for(j=1;j<=9;j++)
        {
            printf("%d ",population[i][j]);

        }
        printf("\n");
    }
    printf("\n\n\n");

    int aa=1;
    while(aa--)
    {
        for(i=1;i<=10;i++)
        {
            for(j=1;j<=10;j++)
            {
                if(i!=j)
                {
                    for(m=1;m<=4;m++)
                    {
                        temp1[m] = population[i][m];
                        temp2[m] = population[j][m];
                         //printf("%d ",temp2[m]);
                    }
                   // printf("\n");
                    for(m=5;m<=8;m++)
                    {
                        temp1[m] = population[j][m];
                        temp2[m] = population[i][m];
                       // printf("%d ",temp2[m]);
                    }
                    //printf("\n");
                }
//                printf("****%d****",check(temp1));
//                break;
                temp1[9] = check(temp1);
                temp2[9] = check(temp2);

                if(temp1[9] < population[i][9])
                {
                    for(k=1;k<=9;k++)
                    {
                        population[i][k] = temp1[k];
                    }
                }
                if(temp2[9] < population[j][9])
                {
                    for(k=1;k<=9;k++)
                    {
                        population[j][k] = temp2[k];
                    }
                }
            }
//            break;
        }
    }

    for(i=1;i<=10;i++)
    {
        for(j=1;j<=9;j++)
        {
            printf("%d ",population[i][j]);

        }
        printf("\n");
    }
    printf("\n\n");

    int best_huristic = 29;
    int index;
    for(i=1;i<=10;i++)
    {
        if(best_huristic > population[i][9])
        {
            best_huristic = population[i][9];
            index = i;
        }
    }
    for(i=1;i<=8;i++)
    {
        printf("%d ",population[index][i]);
    }
    printf("\n best hueristic value %d\n",population[index][9]);

    population[index][1+rand()%8] = 1+rand()%8;

    printf("after mutation huristis value is: %d\n",check(population[index]));
    for(i=1;i<=8;i++)
    {
        printf("%d ",population[index][i]);
    }

    return 0;
}


