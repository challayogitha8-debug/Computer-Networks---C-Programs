#include <stdio.h>
#define INF 999

int main()
{
    int n,i,j,k,u,min;
    int c[10][10],d[10],v[10]={0};

    printf("Enter number of routers: ");
    scanf("%d",&n);

    printf("Enter cost matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            scanf("%d",&c[i][j]);
            if(c[i][j]==0 && i!=j)
                c[i][j]=INF;
        }

    printf("Enter source router: ");
    scanf("%d",&k);
    k--;

    for(i=0;i<n;i++)
        d[i]=c[k][i];

    d[k]=0;

    for(i=0;i<n-1;i++)
    {
        min=INF;
        for(j=0;j<n;j++)
            if(!v[j] && d[j]<min)
                min=d[j],u=j;

        v[u]=1;

        for(j=0;j<n;j++)
            if(!v[j] && d[u]+c[u][j]<d[j])
                d[j]=d[u]+c[u][j];
    }

    printf("\nLSR Shortest Distances:\n");
    for(i=0;i<n;i++)
        printf("Router %d = %d\n",i+1,d[i]);

    return 0;
}