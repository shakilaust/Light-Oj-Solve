#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#define MAX 105
using namespace std;
int cost[MAX][MAX],visit[MAX],ans1,ans2,n;
vector <int> adjList [MAX];
int dfs()
{     int u, i = 1,j, red = 0, black = 0;
    while (true) {
        u = 205;
          for(j=0;j<adjList[i].size();j++){
            if (!visit [adjList [i][j]]) {
                u = adjList [i][j];
                break;
            }
        }
        if (u == 205) break;
        visit[u]=1;
        red += ((int) cost [i][u]);
        black += ((int) cost [u][i]);
        i = u;
    }

    red += ((int) cost [i][1]);
    black += ((int) cost [1][i]);
    return min (red, black);
}
void solve()
{   int u,v,w,i;
    scanf("%d",&n);
    memset(visit,0,sizeof(visit));
    memset(cost,0,sizeof(cost));
    for(i=0;i<=n+1;i++) adjList[i].clear();
    for(i=1;i<=n;i++)
    {
        scanf("%d %d %d",&u,&v,&w);
        cost[u][v]=0;
        cost[v][u]=w;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    visit[1]=1;
    //ans2+=cost[1][adjList[1][1]];
    //ans1+=cost[adjList[1][1]][1];
    printf("%d\n",dfs());
}
int main()
{
    int t,cs;
    scanf("%d",&t);
    for(cs=1;cs<=t;cs++)
    {
        printf("Case %d: ",cs);
        solve();
    }
}
