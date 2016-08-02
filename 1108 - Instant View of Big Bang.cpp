
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

const int N=1005;
int n,m,dist[N];
vector <pii> adj[N];
vector <int> deg[N];
vector <int> res;
bool visit[N];
void dfs(int x)
{
       visit[x]=1;
       int i;
       for(i=0;i<adj[x].size();i++)
       {      int v=adj[x][i].first;
              if(!visit[v]) dfs(v);
       }
}
void BellManFord()
{      memo(visit,0);
       res.clear();
       int i,j,k;
       dist[0]=0;
       for(i=0;i<n-1;i++)
       {
              for(j=0;j<n;j++)
              {
                     for(k=0;k<adj[j].size();k++)
                     {
                            int v=adj[j][k].first;
                            if(dist[v]>dist[j]+adj[j][k].second)
                            {
                                   dist[v]=dist[j]+adj[j][k].second;
                            }
                     }
              }
       }
       bool cycle=false;
           for(j=0;j<n;j++)
              {
                     for(k=0;k<adj[j].size();k++)
                     {
                            int v=adj[j][k].first;
                            if(dist[v]>dist[j]+adj[j][k].second)
                            {
                                   if(!visit[v]) dfs(v);
                                   cycle=1;
                            }
                     }
              }
       if(cycle)
       {    //  sort(res.begin(),res.end());
              for(i=0;i<n;i++)
              {
                     if(visit[i])
                     printf(" %d",i);
              }
              printf("\n");
       }
       else
       printf(" impossible\n");
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
                  adj[i].clear();
                  dist[i]=INF;
           }
           int u,v,c;
           for(i=0;i<m;i++)
           {
                  scanf("%d %d %d",&u,&v,&c);
                  adj[v].pb(mp(u,c));
                 // deg[v].pb(u);
           }
            printf("Case %d:",cs);
            BellManFord();

    }



}
