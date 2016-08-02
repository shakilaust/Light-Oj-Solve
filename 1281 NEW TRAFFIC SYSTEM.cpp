
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

int n,m,k,d,dist[N][12];
struct Graph
{
       int nd,cst,typ;
}in;

struct abc
{
       int node,used,cost;
}inp,prev;

vector<Graph> adj[N];
void Clear()
{
       int i,j;
       for(i=0;i<=n;i++)
       {      adj[i].clear();
              for(j=0;j<=d;j++)
                 dist[i][j]=INF;
       }
}
int Dijkstra()
{      int i;
       queue<abc> q;
       inp.node=inp.used=inp.cost=0;
       q.push(inp);
       dist[0][0]=0;
       while(!q.empty())
       {
              prev=q.front();
              q.pop();

              for(i=0;i<adj[prev.node].size();i++)
              {
                     int u=adj[prev.node][i].nd;
                     int c=adj[prev.node][i].cst;
                     int t=adj[prev.node][i].typ;
                     if(t+prev.used<=d)
                     {
                            t+=prev.used;
                            if(dist[u][t]>prev.cost+c)
                            {
                                   dist[u][t]=prev.cost+c;
                                   inp.node=u;
                                   inp.cost=dist[u][t];
                                   inp.used=t;
                                   q.push(inp);
                            }
                     }

              }
       }
       int ans=INF;
       for(i=0;i<=d;i++)
       {
       ans=min(ans,dist[n-1][i]);
      // printf("dist[n-1][%d]::%d \n",i,dist[n-1][i]);
       }
       return ans;

}
int main()
{
    int cs,t,i,u,v,w;
    scanf("%d",&t);
    for(cs=1;cs<=t;cs++)
    {
           scanf("%d %d %d %d",&n,&m,&k,&d);
           Clear();
           for(i=1;i<=m;i++)
           {
                  scanf("%d %d %d",&u,&v,&w);
                  in.nd=v;
                  in.cst=w;
                  in.typ=0;
                  adj[u].pb(in);

           }
            for(i=1;i<=k;i++)
           {
                  scanf("%d %d %d",&u,&v,&w);
                  in.nd=v;
                  in.cst=w;
                  in.typ=1;
                  adj[u].pb(in);

           }
           int ans=Dijkstra();
           if(ans==INF)
           {
                  printf("Case %d: Impossible\n",cs);
           }
           else printf("Case %d: %d\n",cs,ans);

    }

   return 0;
}
