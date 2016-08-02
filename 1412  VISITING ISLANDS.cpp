
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
#define MAX3(a,b,c) max(a,max(b,c))

double const EPS=3e-8;
using namespace std;


template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
const int N=100005;
struct graph
{
       int totalnodes,diameter;
}tree[N];
bool cmp(graph a,graph b)
{
       if(a.totalnodes==b.totalnodes) return a.diameter>b.diameter;
       return a.totalnodes>b.totalnodes;
}
int dist[N],maxDis,idx;
vector <int> adj[N],best,visited;
void dfs(int u)
{
       int i;
       visited.pb(u);
       for(i=0;i<adj[u].size();i++)
       {
              int v=adj[u][i];
              if(dist[v]<0)
              {
                     dist[v]=dist[u]+1;
                     dfs(v);
              }
       }

}
void FindBest(int from)
{      visited.clear();
       int i;
       dist[from]=0;
       dfs(from);
       int best=from;
       for(i=0;i<visited.size();i++)
       if(dist[visited[i]]>dist[best]) best=visited[i];
       if(dist[best]+1>maxDis) maxDis=dist[best]+1;
       for(i=0;i<visited.size();i++) dist[visited[i]]=-1;
       visited.clear();
       dist[best]=0;
       dfs(best);
       for(i=0;i<visited.size();i++)
       if(dist[visited[i]]>dist[best]) best=visited[i];
       if(dist[best]+1>maxDis) maxDis=dist[best]+1;
       tree[idx].totalnodes=visited.size();
       tree[idx++].diameter=dist[best]+1;

}
void bestdfs(int node)
{

}
int main()
{

    //freopen("in.txt", "r", stdin);
    int t;
    sc(t);
    FOR(cs,1,t)
    {
           int n,m,u,v,i,k,in,j;
           scanf("%d %d",&n,&m);
           for(i=1;i<=n;i++)
           {
                  dist[i]=-1;
                  adj[i].clear();
           }
           for(i=0;i<m;i++)
           {
                  scanf("%d %d",&u,&v);
                  adj[u].pb(v);
                  adj[v].pb(u);
           }
           idx=0,maxDis=-1;
           for(i=1;i<=n;i++)
           {
                  if(dist[i]<0)
                  {
                         FindBest(i);
                  }
                //  printf("here\n");
           }
           //printf("maxDis:: %d\n",maxDis);
           sort(tree,tree+idx,cmp);
           /*for(i=0;i<idx;i++)
           {
                  printf("treenode:: %d diameter:: %d\n",tree[i].totalnodes,tree[i].diameter);
           } */
           scanf("%d",&k);
           printf("Case %d:\n",cs);
           for(i=0;i<k;i++)
           {
                  scanf("%d",&in);
                  if(in<=maxDis)
                  {
                         printf("%d\n",in-1);
                         continue;
                  }
                  if(in>tree[0].totalnodes)
                  {
                         printf("impossible\n");
                         continue;
                  }
                  int minbest=(tree[0].diameter+(in-tree[0].diameter)*2-1);
                  for(j=1;j<idx && tree[j].totalnodes>=in;j++)
                  {
                         minbest=min(minbest,(tree[j].diameter+(in-tree[j].diameter)*2-1));
                  }
                  printf("%d\n",minbest);
           }


    }



}
