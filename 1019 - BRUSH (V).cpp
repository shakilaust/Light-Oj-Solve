
#include <stdio.h>
#include <algorithm>
#define INF 1<<29
#define MAX 205
using namespace std;
int node,edge,i,j,k,kase=1,test,des,u,v,w;
int adjMat[MAX][MAX];
void clear()
{
    for(i=1;i<=node;i++)
       for(j=1;j<=node;j++)
          if(i==j) adjMat[i][j]=0;
          else adjMat[i][j]=INF;
}
int main()
{   //freopen("input.txt","r",stdin);
    for(scanf("%d",&test);kase<=test;kase++)
    {
        scanf("%d %d",&node,&edge);
        clear();
        while(edge--)
        {
            scanf("%d %d %d",&u,&v,&w);
            if(adjMat[u][v]==INF)
            {
            adjMat[u][v]=w;
            adjMat[v][u]=w;
            }
            else
            {
                adjMat[u][v]=min(adjMat[u][v],w);
                adjMat[v][u]=min(adjMat[v][u],w);
            }
        }
        for(k=1;k<=node;k++)
           for(i=1;i<=node;i++)
               for(j=1;j<=node;j++)
                  adjMat[i][j]=min(adjMat[i][j],(adjMat[i][k]+adjMat[k][j]));
           if(adjMat[1][node]==INF) printf("Case %d: Impossible\n",kase);
           else printf("Case %d: %d\n",kase,adjMat[1][node]);
    }
}
