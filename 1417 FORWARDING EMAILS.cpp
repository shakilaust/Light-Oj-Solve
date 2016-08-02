
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
const int inf=INF;
const int N=50005;

vector <int> adj[N],dag[N],input;
vector <pii> res;
bool visit[N];
int color[N],num,col,discover[N],low[N],in[N],out[N],n,dp[N];
stack<int> s;

map <int,int> mapy,rog;
bool cmp(pii a,pii b)
{
       if(a.second==b.second) return a.first<b.first;
       else return a.second>b.second;
}
void Tarjan(int u)
{
       discover[u]=low[u]=++num;
       s.push(u);
       int i;
       visit[u]=1;
       for(i=0;i<adj[u].size();i++)
       {
              int v=adj[u][i];
              if(discover[v]==-1)
              {
                     Tarjan(v);
                     low[u]=min(low[u],low[v]);
              }
              else if(visit[v])
              low[u]=min(low[u],discover[v]);
       }
       if(low[u]==discover[u])
       {      int t,total=0;
             int mini=100000;
              ++col;
              do{
                     t=s.top();
                     s.pop();
                     color[t]=col;
                     mini=min(mini,t);
                     visit[t]=0;
                     total+=1;
              }while(t!=u);
              input.pb(mini);
              rog[col]=mini;
              mapy[mini]=total;

       }
}
int DP(int u)
{
       if(dp[u]!=-1) return dp[u];
       dp[u]=mapy[u];
       int i;
       for(i=0;i<dag[u].size();i++)
       {
              int v=dag[u][i];
              dp[u]+=DP(v);
       }
       return dp[u];

}
int solve()
{      int i;
       memo(discover,-1);
       memo(visit,0);
       input.clear();
       mapy.clear();
       rog.clear();
       col=num=0;
       while(!s.empty()) s.pop();
       for(i=1;i<=n;i++)
       {
              if(discover[i]==-1) Tarjan(i);

       }
      // for(i=1;i<=n;i++) adj[i].clear();
       memo(out,0);
       memo(in,0);
       int j;
      // printf("col:: %d\n",col);
       for(i=1;i<=n;i++)
       {    // printf("i:: %d\n",i);
              for(j=0;j<adj[i].size();j++)
              {
                     int v=adj[i][j];
                     if(color[v]!=color[i])
                     {       dag[rog[color[i]]].pb(rog[color[v]]);
                          //   printf("u::->  %d v:: %d\n",rog[color[i]],rog[color[v]]);

                     }
              }
       }
       res.clear();
       for(i=0;i<input.size();i++)
       {
              res.pb(mp(input[i],DP(input[i])));
       }
       sort(res.begin(),res.end(),cmp);

       return res[0].first;

}
int main()
{

    //freopen("in.txt", "r", stdin);
    int cs,t,i,u,v;
    scanf("%d",&t);
    for(cs=1;cs<=t;cs++)
    {
           scanf("%d",&n);
           for(i=1;i<=n;i++)
           {
                  adj[i].clear();
                  dag[i].clear();
                  dp[i]=-1;
           }
           for(i=1;i<=n;i++)
           {
                  scanf("%d %d",&u,&v);
                  adj[u].pb(v);
           }
           printf("Case %d: %d\n",cs,solve());
    }
}
/*
1
5
1 2
2 1
5 3
3 4
4 5
*/
