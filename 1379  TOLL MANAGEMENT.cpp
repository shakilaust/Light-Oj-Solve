
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
#define INF 1<<28
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define memo(a,b) memset((a),(b),sizeof(a))
#define G() getchar()
#define MAX3(a,b,c) max(a,max(b,c))

double const EPS=3e-8;
using namespace std;


template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }

const int MAXN = 10000;

int dist[2][MAXN],n,m,p,s,t;

vector < pii > adj [MAXN + 5] , Radj [MAXN + 5];

struct edge
{
       int u,v,c;
}inp[ 5 * MAXN + 5];

struct Graph
{
       int node,cost;
       Graph() {}
       Graph(int u,int c)
       {
              node = u;
              cost = c;
       }
       bool operator < ( const Graph &A) const
       {
              return A.cost < cost;
       }
};

void Clear()
{
       int i , j;
       for ( i = 0 ; i <= n ; i++ )
       {
              adj[i].clear();
              Radj[i].clear();
              for ( j = 0 ; j < 2 ; j++ )
              {
                     dist[j][i] = INF;
              }
       }
}
void input()
{
       scanf("%d %d %d %d %d",&n,&m,&s,&t,&p);
       Clear();
       int i;
       for( i = 0 ; i < m ; i++ )
       {
              scanf("%d %d %d",&inp[i].u,&inp[i].v,&inp[i].c);
              adj[inp[i].u].pb(mp(inp[i].v,inp[i].c));
              Radj[inp[i].v].pb(mp(inp[i].u,inp[i].c));
       }
}
void Direct_Dijkstra()
{
       priority_queue < Graph > pq;
       pq.push(Graph(s,0));
       int i ,sz , u ;
       while(!pq.empty())
       {
              Graph now = pq.top();
              pq.pop();
              if(dist[0][now.node]!=INF) continue; // already result is found
              else dist[0][now.node] = now.cost ;
              u = now.node ;
              sz = adj[u].size();
              for ( i = 0 ; i < sz ; i++ )
              {
                     int v = adj[u][i].first;
                     int dis = adj[u][i].second + now.cost;
                     if(dist[0][v]!=INF) continue;
                     pq.push(Graph(v,dis));
              }

       }
}
void Reverse_Dijkstra()
{
       priority_queue < Graph > pq;
       pq.push(Graph(t,0));
       int i ,sz , u ;
       while(!pq.empty())
       {
              Graph now = pq.top();
              pq.pop();
              if(dist[1][now.node]!=INF) continue; // already result is found
              else dist[1][now.node] = now.cost ;
              u = now.node ;
              sz = Radj[u].size();
              for ( i = 0 ; i < sz ; i++ )
              {
                     int v = Radj[u][i].first;
                     int dis = Radj[u][i].second + now.cost;
                     if(dist[1][v]!=INF) continue;
                     pq.push(Graph(v,dis));
              }

       }
}
int solve()
{
       int ans = -1;
       Direct_Dijkstra();
       Reverse_Dijkstra();
       int i;
       for ( i = 0 ; i < m ; i++ )
       {
              int x = inp[i].u;
              int y = inp[i].v;
              int w = inp[i].c;
              if(dist[0][x]==INF || dist[1][y]==INF) continue;
              if(dist[0][x] + dist[1][y] + w > p ) continue;
              if(ans < w) ans = w;
       }
       return ans;
}
int main()
{

    //freopen("in.txt", "r", stdin);
    int cs, t;
    scanf("%d",&t);
    for ( cs = 1 ; cs <= t ; cs++ )
    {
           input();
           printf("Case %d: %d\n",cs,solve());
    }


}
