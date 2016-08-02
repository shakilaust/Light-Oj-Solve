
 //BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopner soman boro
 Author :: Shakil Ahmed
.............AUST_CSE27.........
 prob   ::
 Type   ::
 verdict::
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>
#include <set>
#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <list>
#include <map>
#include <queue>
#include <sstream>
#include <utility>
#define pf(a) printf("%d\n",a)
#define pf2(a,b) printf("%d %d\n",a,b)
#define pfcs(cs,a) printf("Case %d: %d\n",cs,a)
#define sc(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
#define pi acos(-1.0)
#define ff first
#define LL long long
#define ss second
#define rep(i,n) for(i = 0; i < n; i++)
#define REP(i,n) for(i=n;i>=0;i--)
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define ROF(i,a,b) for(int i = a; i >= b; i--)
#define re return
#define QI queue<int>
#define SI stack<int>
#define pii pair <int,int>
#define MAX
#define MOD
#define INF 1<<30
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define memo(a,b) memset((a),(b),sizeof(a))
#define G() getchar()


using namespace std;


template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
vector <int> res[30005];
vector < pair<int,int> > G[30005];
int cost[30005],node;
bool visit[30005];
void input()
{      int i,u,v,w;
       scanf("%d",&node);
       for(i=0;i<node-1;i++)
       {
              scanf("%d %d %d",&u,&v,&w);
              G[u].pb(mp(v,w));
              G[v].pb(mp(u,w));
       }
}
void clear()
{
       int i;
       for(i=0;i<node;i++)
       {
              res[i].clear();
              G[i].clear();
       }
}
void solve()
{      int i,u,v,j,mx=-1,farthest_node;
       queue<int> q;
       memo(visit,0);
       memo(cost,0);
       q.push(0);
       cost[0]=0;
       res[0].pb(0);
       visit[0]=1;
       while(!q.empty())
       {
              v=q.front();
              q.pop();
              for(i=0;i<G[v].size();i++)
              {
                     u=G[v][i].first;
                     if(!visit[u])
                     {      q.push(u);
                            visit[u]=1;
                            cost[u]=cost[v]+G[v][i].second;
                            res[u].pb(cost[u]);
                            if(cost[u]>mx)
                            {
                                   farthest_node=u;
                                   mx=cost[u];
                            }
                     }
              }
       }
       mx=-1;
       while(!q.empty()) q.pop();
       memo(visit,0);
       memo(cost,0);
       q.push(farthest_node);
       cost[farthest_node]=0;
       res[farthest_node].pb(0);
       visit[farthest_node]=1;
       while(!q.empty())
       {
              v=q.front();
              q.pop();
              for(i=0;i<G[v].size();i++)
              {
                     u=G[v][i].first;
                     if(!visit[u])
                     {      q.push(u);
                            visit[u]=1;
                            cost[u]=cost[v]+G[v][i].second;
                            res[u].pb(cost[u]);
                            if(cost[u]>mx)
                            {
                                   farthest_node=u;
                                   mx=cost[u];
                            }
                     }
              }
       }
       while(!q.empty()) q.pop();
       memo(visit,0);
       memo(cost,0);
       q.push(farthest_node);
       cost[farthest_node]=0;
       res[farthest_node].pb(0);
       visit[farthest_node]=1;
       mx=-1;
       while(!q.empty())
       {
              v=q.front();
              q.pop();
              for(i=0;i<G[v].size();i++)
              {
                     u=G[v][i].first;
                     if(!visit[u])
                     {      q.push(u);
                            visit[u]=1;
                            cost[u]=cost[v]+G[v][i].second;
                            res[u].pb(cost[u]);
                            if(cost[u]>mx)
                            {
                                   farthest_node=u;
                                   mx=cost[u];
                            }
                     }
              }
       }
       for(i=0;i<node;i++)
       printf("%d\n",max(max(res[i][0],res[i][1]),res[i][2]));
      clear();

}

int main()
{

    //freopen("in.txt", "r", stdin);
    int cs,t;
    scanf("%d",&t);
    for(cs=1;cs<=t;cs++)
    {
           input();
           printf("Case %d:\n",cs);
           solve();
    }



}
