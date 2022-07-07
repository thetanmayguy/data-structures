#include <stdio.h>
void bfs(int n,int s,int vis[],int mat[][10])
{
    int q[10],u,v,f=0,r=0;
    vis[s]=1;
    q[r]=s;
    while(f<=r)
    {
        u=q[f++];
        for(v=0;v<n;v++)
        {
            if((mat[u][v]==1)&&(vis[v]==0))
            {
                q[++r]=v;
                vis[v]=1;
            }
        }
    }
}
int main()
{
    int mat[10][10],vis[10]={0},n,s,i,j;
    printf("Enter the no. of vertices:");
    scanf("%d",&n);
    printf("Enter the adjacency matrix:-\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&mat[i][j]);
    for(;;)
    {
        for(i=0;i<n;i++)
            vis[i]=0;
        printf("Enter source vetex or Enter -1 to terminate:");
        scanf("%d",&s);
        if(s==-1)
            return 0;
        bfs(n,s,vis,mat);
        for(i=0;i<n;i++)
        {
            if(vis[i]==1)
                printf("%d is reachable from %d\n",i,s);
            else
                printf("%d is not reachable from %d\n",i,s);
        }
        printf("--------------------------------------------------\n");
    }
    return 0;
}