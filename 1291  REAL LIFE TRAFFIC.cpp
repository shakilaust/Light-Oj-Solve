
 //BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopner soman boro
 Author :: Shakil Ahmed
.............AUST_CSE27.........
 prob   ::
 Type   ::
 verdict::
 */
#include <bits/stdc++.h>

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

const int N=10005;

int discover[N],low[N],seq,col,color[N],n,m,deg[N];
bool visit[N];
stack <int> s;
vector <int> adj[N];
void Tarjan(int u,int par)
{
       discover[u]=low[u]=++seq;
       s.push(u);
       int i;
       visit[u]=1;
       //printf("u::: %d par:: %d\n",u,par);
       for(i=0;i<adj[u].size();++i)
       {
              int v=adj[u][i];
              if(v==par) continue;
               if(visit[v]) low[u]=min(low[u],discover[v]);
               else
               {
                     Tarjan(v,u);
                     low[u]=min(low[u],low[v]);
               }

       }
       if(low[u]==discover[u])
       {
              ++col;
              while(!s.empty())
              {
                     int val=s.top();
                     s.pop();
                     color[val]=col;

                     if(u==val) break;
              }
       }
}
int solve()
{
       seq=col=0;
       memo(discover,-1);
       memo(visit,0);
       while(!s.empty()) s.pop();
       Tarjan(0,-1);
       int ans=0;
       int i,j,u,v;
       memo(deg,0);
       for(i=0;i<n;i++)
       {
              for(j=0;j<adj[i].size();j++)
              {
                     u=i;
                     v=adj[i][j];
                     if(color[u]!=color[v])
                     {                            deg[color[u]]++;
                            deg[color[v]]++;
                     }
              }
       }
       for(i=1;i<=col;i++)
       {
              if(deg[i]==2) ans++;

       }

       return (ans+1)/2;
}
int main()
{  int cs,t,i,u,v;
   scanf("%d",&t);
   for(cs=1;cs<=t;cs++)
   {
          scanf("%d %d",&n,&m);
          for(i=1;i<=m;i++)
          {
                 scanf("%d %d",&u,&v);
                 adj[u].pb(v);
                 adj[v].pb(u);
          }
          printf("Case %d: %d\n",cs,solve());
          for(i=0;i<=n;i++) adj[i].clear();
   }
   return 0;
}
