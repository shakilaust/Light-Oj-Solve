
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

const int N=50005;
vector <int> adj[N];
int par[N],in[N],cost[N],n,mx;
bool vis[N];

void bfs()
{
       queue <int> q;
       q.push(in[0]);
       cost[in[0]]=0;
       while(!q.empty())
       {
              int u=q.front();
              q.pop();
              int i,sz=SZ(adj[u]);
              for(i=0;i<sz;i++)
              {
                    int v=adj[u][i];
                    if(cost[v]==-1)
                    {
                           cost[v]=cost[u]+1;
                           q.push(v);
                           par[v]=u;
                           if(v==in[n-1]) return ;
                    }
              }
       }
}
void print(int s,int d)
{
       if(s==d)
       {
              printf("%d",s);
              return ;
       }
       else
       {
              print(s,par[d]);
              printf(" %d",d);
       }

}

int main()
{

    //freopen("in.txt", "r", stdin);
   int t;
   memo(cost,-1);
   sc(t);
   FOR(cs,1,t)
   {
          scanf("%d",&n);
          int i;

          for(i=0;i<n;i++)
          {
                 scanf("%d",&in[i]);

          }
          for(i=0;i<n-1;i++)
          {
                 adj[in[i]].pb(in[i+1]);
                 adj[in[i+1]].pb(in[i]);
          }
          for(i=0;i<n;i++)
          {
               //  if(cost[in[i]]==-1) continue;
                 cost[in[i]]=-1;
                 sort(adj[in[i]].begin(),adj[in[i]].end());
          }
          printf("Case %d:\n",cs);
          bfs();
          print(in[0],in[n-1]);
          printf("\n");
          for(i=0;i<n;i++)
          {
                 adj[in[i]].clear();
          }

   }


}
