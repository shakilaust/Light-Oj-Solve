
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
const int N=105;
vector <pii> adj[N];
int n,m,s,d,c,dis[N][N],fuel[N];
struct node
{
       int from,gas,price;
       node() {}
       node(int _u,int _v,int _c)
       {
              from=_u;
              gas=_v;
              price=_c;
       }
       bool operator < ( const node & x) const
       {
              return price>x.price;
       }
};
priority_queue <node> pq;

int  dijkstra(int s,int t,int cap)
{

       int i,j,u,v,c,d,g,p;
       while(!pq.empty()) pq.pop();
       for(i=0;i<N;i++)
          for(j=0;j<N;j++) dis[i][j]=INF;
       dis[s][0]=0;
       pq.push(node(s,0,0));
       while(!pq.empty())
       {
              node cur=pq.top();
              pq.pop();
              u=cur.from;
              g=cur.gas;
              p=cur.price;
           //   printf("u::%d p::%d  gas::%d jacce::%d ase::%d\n",u,p,g,dis[u][g+1],dis[u][g]);
              if(u==t) return p;
              if(g+1<=cap && dis[u][g+1]>dis[u][g]+fuel[u])
              {
                     dis[u][g+1]=dis[u][g]+fuel[u];
                     pq.push(node(u,g+1,dis[u][g+1]));
              }
              int i,sz=adj[u].size();
              for(i=0;i<sz;++i)
              {
                     v=adj[u][i].first;
                     d=adj[u][i].second;
                     if(d>g) continue;
                     if(dis[v][g-d]>dis[u][g])
                     {
                            dis[v][g-d]=dis[u][g];
                            pq.push(node(v,g-d,p));
                     }

              }


       }

    return -1;
}
void solve()
{
   int q,capacity,source,destination,i;
   scanf("%d",&q);
   for(i=0;i<q;i++)
   {
          scanf("%d %d %d",&capacity,&source,&destination);
          int ans=dijkstra(source,destination,capacity);
          if(ans==-1) printf("impossible\n");
          else printf("%d\n",ans);
   }


}
int main()
{

    //freopen("in.txt", "r", stdin);
    int cs,t,i;
    scanf("%d",&t);
    for(cs=1;cs<=t;cs++)
    {
           scanf("%d %d",&n,&m);
           for(i=0;i<n;i++)
           {
                  scanf("%d",&fuel[i]);
                  adj[i].clear();
           }
           int u,v,cost;
           for(i=0;i<m;i++)
           {
                  scanf("%d %d %d",&u,&v,&cost);
                  adj[u].pb(mp(v,cost));
                  adj[v].pb(mp(u,cost));
           }
           printf("Case %d:\n",cs);
           solve();
    }


}
