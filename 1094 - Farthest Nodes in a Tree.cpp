
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 30005
using namespace std;
int cs,node,visit[MAX],cost[MAX];
vector < pair <int,int> > g[MAX];
void graph_clear()
{
    int i;
    for(i=0;i<MAX;i++) g[i].clear();
}
void input()
{    graph_clear();
    int i,u,v,c;
    scanf("%d",&node);
    for(i=1;i<node;i++)
    {
        scanf("%d %d %d",&u,&v,&c);
        g[u].push_back(make_pair(v,c));
        g[v].push_back(make_pair(u,c));
    }
}
void solve()
{   int i,mx=-1,farthest_node,v,u,c;
    input();
    memset(visit,0,sizeof(visit));
     memset(cost,0,sizeof(cost));
    queue <int> q;
    q.push(0);
    while(!q.empty())
    {
        v=q.front();
        q.pop();
        visit[v]=1;
        for(i=0;i<g[v].size();i++)
        {
            u=g[v][i].first;
            cost[u]=cost[v]+g[v][i].second;
            if(!visit[u])
            {
                q.push(u);
                if(cost[u]>mx)
                {
                    mx=cost[u];
                    farthest_node=u;
                }
            }
        }
    }
    mx=-1;
    q.push(farthest_node);
    memset(visit,0,sizeof(visit));
    memset(cost,0,sizeof(cost));
     while(!q.empty())
    {
        v=q.front();
        q.pop();
        visit[v]=1;
        for(i=0;i<g[v].size();i++)
        {
            u=g[v][i].first;
            cost[u]=cost[v]+g[v][i].second;
            if(!visit[u])
            {
                q.push(u);
                if(cost[u]>mx)
                {
                    mx=cost[u];
                    farthest_node=u;
                }
            }
        }
    }
    printf("Case %d: %d\n",cs,mx);


}
int main()
{  // freopen("shakil.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(cs=1;cs<=t;cs++)
    {
        solve();
    }
}
