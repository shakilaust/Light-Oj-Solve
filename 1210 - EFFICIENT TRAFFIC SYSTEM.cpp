
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
const int N=20005;
vector <int> adj[N];
bool visit[N];
int discover[N],low[N],out[N],in[N],color[N],col,num,n,m,top;
stack <int> s;
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
       {      int t;
              ++col;
              do{
                     t=s.top();
                     s.pop();
                     color[t]=col;
                     visit[t]=0;
              }while(t!=u);
       }
}
int solve()
{
       int i,j,ans,ans1,ans2;
       memo(discover,-1);
       memo(visit,0);
       num=col=top=0;
       for(i=1;i<=n;i++)
       {
              if(discover[i]==-1) Tarjan(i);
       }
       memo(in,0);
       memo(out,0);
       for(i=1;i<=n;i++)
       {
              for(j=0;j<adj[i].size();j++)
              {
                     int v=adj[i][j];
                     if(color[v]!=color[i])
                     {
                            ++in[color[v]];
                            ++out[color[i]];
                     }
              }
       }
       ans1=ans2=0;
       if(col==1) ans=0;
       else
       {
              for(i=1;i<=col;i++)
              {
                     if(in[i]==0) ++ans1;
                     if(out[i]==0) ++ans2;
              }
              ans=max(ans1,ans2);
       }
       return ans;
}
void CLR()
{      int i;
       for(i=1;i<=n;i++) adj[i].clear();
}
int main()
{
       int cs,t;
       scanf("%d",&t);
       for(cs=1;cs<=t;cs++)
       {
              int i,u,v;
              scanf("%d %d",&n,&m);
              CLR();
              for(i=1;i<=m;i++)
              {
                     scanf("%d %d",&u,&v);
                     adj[u].pb(v);
              }
               printf("Case %d: %d\n",cs,solve());



       }
   return 0;
}
