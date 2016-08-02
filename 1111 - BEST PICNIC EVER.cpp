
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#define MAX 1000
#define pb push_back
using namespace std;
vector <int > road[MAX*10+5],people;
int n,m,k,cs,visit[MAX+5],cost[MAX+5];
void clear()
{
    int i=0;
    people.clear();
    for(i=0;i<=n;i++)
    {
        road[i].clear();
        cost[i]=0;
    }
}
void input()
{
    int u,v,i;
    clear();
    scanf("%d %d %d",&k,&n,&m);
    for(i=0;i<k;i++)
    {
        scanf("%d",&u);
        people.pb(u);
    }
    for(i=0;i<m;i++)
    {
        scanf("%d %d",&u,&v);
        road[u].pb(v);
    }
}
void dfs(int start)
{   int i;
    visit[start]=1;
    cost[start]++;
    for(i=0;i<road[start].size();i++)
    {
        if(!visit[road[start][i]])
        dfs(road[start][i]);
    }
}
void solve()
{   int i;
    input();
    for(i=0;i<people.size();i++)
    {
        memset(visit,0,sizeof(visit));
        dfs(people[i]);
    }
    int ans=0;
    for(i=1;i<=n;i++)
    {
        if(cost[i]==k) ans++;
    }
    printf("Case %d: %d\n",cs,ans);
}
int main()
{  // freopen("shakil.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(cs=1;cs<=t;cs++) solve();
}
