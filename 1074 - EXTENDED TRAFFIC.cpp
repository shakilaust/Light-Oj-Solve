
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
#define INF 1<<20
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
const int inf=(22*22*22);
const int N=205;
vector <pii> adj[N];
bool neg[205];
int dist[N],n,m,d[N];
void BellManFord()
{
       int i,j,k,q;

       for(i=1;i<=n;i++) { dist[i]=inf; neg[i]=0 ;}
       dist[1]=0;
       for(i=0;i<n-1;i++)
       {
              for(j=1;j<=n;j++)
                for(k=0;k<adj[j].size();k++)
                {
                       int v=adj[j][k].first;
                       if(dist[j]!=inf  && dist[v]>dist[j]+adj[j][k].second)
                       {
                              dist[v]=dist[j]+adj[j][k].second;
                       }
                }
       }
       // checking for neg cycle
         for(j=1;j<=n;j++)
                for(k=0;k<adj[j].size();k++)
                {
                       int v=adj[j][k].first;
                       if(dist[v]>dist[j]+adj[j][k].second)
                       {
                              neg[v]=1;
                       }
                }


       scanf("%d",&q);
       for(i=1;i<=q;i++)
       {      int in;
              scanf("%d",&in);
              if(dist[in]==inf || dist[in]<3 || in>n || in<=0 || neg[in])
              {
                      puts("?");
              }
              else printf("%d\n", dist[in]);
       }

}
int main()
{

    //freopen("in.txt", "r", stdin);
    int i,u,v,c,t,cs;
    scanf("%d",&t);
    for(cs=1;cs<=t;cs++)
    {      (scanf("%d",&n)==1);
           for(i=1;i<=n;i++)
           {
                  adj[i].clear();
                  scanf("%d",&d[i]);
           }
           scanf("%d",&m);
           for(i=1;i<=m;i++)
           {
                  scanf("%d %d",&u,&v);
                  c=(d[v]-d[u])*(d[v]-d[u])*(d[v]-d[u]);

                  adj[u].pb(mp(v,c));
           }
           printf("Case %d:\n",cs);
           BellManFord();

    }


}
