#include <stdio.h>
#define INF 999

int main()
{
    int n, a[10][10], d[10], p[10], v[10]={0};
    int i,j,s,dest,k,min,path[10],c=0;

    printf("Enter the number of nodes in the graph:\n");
    scanf("%d",&n);

    printf("\n Our assumption is Node names by default starts with 0,1,2, and so on.\n");

    for(i=0;i<n;i++)
    {
        printf("\n Enter distance from %d to all other nodes: ",i);
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    }

    printf("Enter the source node: ");
    scanf("%d",&s);
    printf("Enter the destination node: ");
    scanf("%d",&dest);

    for(i=0;i<n;i++)
        d[i]=INF, p[i]=-1;

    d[s]=0;

    for(i=0;i<n;i++)
    {
        min=INF;
        k=-1;

        for(j=0;j<n;j++)
            if(!v[j] && d[j]<min)
                min=d[j],k=j;

        if(k==-1) break;
        v[k]=1;

        for(j=0;j<n;j++)
            if(a[k][j]>0 && !v[j] && d[k]+a[k][j]<d[j])
                d[j]=d[k]+a[k][j],p[j]=k;
    }

    if(d[dest]==INF)
        printf("No path exists");
    else
    {
        for(k=dest;k!=-1;k=p[k])
            path[c++]=k;

        printf("The shortestpath is :");

        for(i=c-1;i>=0;i--)
            printf("%d%s",path[i],i?"->":"");
    }

    return 0;
}