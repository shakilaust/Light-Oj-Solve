
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
const int N=5005;
int dist[N][2],n,R,con[N];
vector<pii> adj[N];
void Clear()
{
       int i;
       for(i=1;i<=n;i++)
       {
              adj[i].clear();
              dist[i][0]=dist[i][1]=INF;
       }
}
void adjust(int x,int dis)
{
       if(dis<dist[x][0])
       {
              dist[x][1]=dist[x][0];
              dist[x][0]=dis;
       }
       else if(dist[x][0]!=dis) dist[x][1]=dis;
}

int Dijkstra()
{
      // memo(dist,N);
      //printf("here\n");
       memo(con,0);
       int i,j;
       dist[1][0]=0;
       for(i=1;i<=2*n;i++)
       {      int u,mx=INF;
              for(j=1;j<=n;j++)
              {
                     if(con[j]<2 && dist[j][con[j]]<mx)
                     {
                            mx=dist[j][con[j]];
                            u=j;
                     }
              }
                     int idx=con[u];
                     con[u]++;
                     if(con[n]==2) break;
                     for(j=0;j<adj[u].size();j++)
                     {
                            int to=adj[u][j].first;
                            if(con[to]<2 && dist[to][1]>dist[u][idx]+adj[u][j].second)
                            {
                                   adjust(to,dist[u][idx]+adj[u][j].second);
                            }
                     }
       }

       return dist[n][1];
}
int main()
{
    int cs,t,i;
    scanf("%d",&t);
    for(cs=1;cs<=t;cs++)
    {
           scanf("%d %d",&n,&R);
           Clear();
           for(i=1;i<=R;i++)
           {      int u,v,c;
                  scanf("%d %d %d",&u,&v,&c);
                  adj[u].pb(mp(v,c));
                  adj[v].pb(mp(u,c));
           }
           printf("Case %d: %d\n",cs,Dijkstra());
    }
   return 0;
}
