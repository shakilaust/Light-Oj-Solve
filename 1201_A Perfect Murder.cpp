

 //BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopner soman boro
 Author :: Shakil Ahmed
.............AUST_CSE27.........
 prob   :: Loj 1251
 Type   :: Minimum vertex cover
 verdict:: WA
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
int N,adj[1005][1005],deg[1005],dp[1005][2],M;
bool vis[1005][2],col[1005];

int DP(int u,int isGurd,int perent)
{
      // if(deg[u]==0) return 1;
       if(vis[u][isGurd]) return dp[u][isGurd];
       vis[u][isGurd]=1;
       col[u]=1;
       int i,sum=0;
       for(i=0;i<deg[u];i++)
       {
              int v=adj[u][i];
              if(v!=perent)
              {
                     if(!isGurd) sum+=DP(v,1,u) ; // bosatei hobe
                     else sum+=min(DP(v,1,u),DP(v,0,u));
              }
       }
       return dp[u][isGurd]=sum+isGurd;
}
int main()
{

    //freopen("in.txt", "r", stdin);
    int cs,t;
    scanf("%d",&t);
    for(cs=1;cs<=t;cs++)
    {
          int i,j,u,v;
          scanf("%d %d",&N,&M);
          for(i=1;i<=N;i++) { deg[i]=0; vis[i][0]=0; vis[i][1]=0; col[i]=0;}
          for(i=1;i<=M;i++)
          {
                 scanf("%d %d",&u, &v);
                 adj[u][deg[u]++]=v;
                 adj[v][deg[v]++]=u;
          }
          int ans=0;
          for(i=1;i<=N;i++)
          {      if(!col[i])
                 ans+=min(DP(i,0,-1),DP(i,1,-1));
          }
          printf("Case %d: %d\n",cs,N-ans);
    }



}
