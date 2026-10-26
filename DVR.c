#include <stdio.h>
#define INF 999

int main()
{
    int n,i,j,k,d[10][10];

    printf("Enter number of routers: ");
    scanf("%d",&n);

    printf("Enter cost matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            scanf("%d",&d[i][j]);
            if(d[i][j]==0 && i!=j)
                d[i][j]=INF;
        }

    for(k=0;k<n;k++)
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if(d[i][k]+d[k][j]<d[i][j])
                    d[i][j]=d[i][k]+d[k][j];

    printf("\nDVR Routing Table:\n");
    for(i=0;i<n;i++)
    {
        printf("Router %d: ",i+1);
        for(j=0;j<n;j++)
            printf("%d ",d[i][j]);
        printf("\n");
    }

    return 0;
}