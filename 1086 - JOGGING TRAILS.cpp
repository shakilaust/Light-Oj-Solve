
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
#define INF 1<<28

#define ALL(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define memo(a,b) memset((a),(b),sizeof(a))
#define G() getchar()
#define MAX3(a,b,c) max(a,max(b,c))
#define FIND(N,pos) ((N) & (1<< (pos)))
double const EPS=3e-8;
using namespace std;

int SET(int N,int pos) { return N=N | (1<<pos); }

int g[16][16],deg[16];
long long int dis[16][16];
 vector <int> oddEdg;
bool visit[20];
int sz;
long long int dp[(1<<15)+10];

long long int DP(int mask)
{
       if(dp[mask]!=-1) return dp[mask];
       if((mask==(1<<oddEdg.size())-1))  return 0;
       int i,ax=0,j;
       for(i=0;i<oddEdg.size();i++)
       {      if(FIND(mask,i)) continue;
              mask=SET(mask,i);
              ax=0;
              for(j=0;j<oddEdg.size();j++)
              {
                     if(j==i || FIND(mask,j)) continue;

                             if(!ax)
                            {

                                   dp[mask]=dis[oddEdg[i]][oddEdg[j]]+DP(SET(mask,j));
                                   ax=1;

                            }

                            else{
                                    dp[mask]=min(dp[mask],dis[oddEdg[i]][oddEdg[j]]+DP(SET(mask,j)));
                                }



              }
              break;

       }

       return dp[mask];
}
int main()
{

       int cs,t,n,m,i,j;
       scanf("%d",&t);
       for(cs=1;cs<=t;cs++)
       {

              scanf("%d %d",&n,&m);
              for(i=1;i<=n;i++)
              {
                     for(j=1;j<=n;j++)
                     {

                            dis[i][j]=INF;
                     }
                     dis[i][i]=0;
                     deg[i]=0;
                     visit[i]=0;

              }
              int u,v,noOddnode=0;
              long long int total_C=0,c;
              for(i=1;i<=m;i++)
              {
                     scanf("%d %d %lld",&u,&v,&c);
                     dis[u][v]=min(dis[u][v],c);
                     dis[v][u]=min(dis[v][u],c);
                     deg[u]++;
                     deg[v]++;
                     total_C+=c;
              }
              int v1=-1,v2=-1;
             oddEdg.clear();
              for(i=1;i<=n;i++)
              {
                     if(deg[i] & 1)
                     {
                            if(v1==-1)
                            {
                                   v1=i;
                            }
                            else
                            {
                                   v2=i;
                            }
                            oddEdg.pb(i);
                            noOddnode++;
                     }
              }

              if(!noOddnode)
              {
                     printf("Case %d: %lld\n",cs,total_C);
              }
              else
              {
                     int k;
                     for(k=1;k<=n;k++)
                     {
                            for(i=1;i<=n;i++)
                            {
                                   for(j=1;j<=n;j++)
                                   {
                                          dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                                   }
                            }
                     }


                     sz=oddEdg.size();

                     memo(dp,-1);
                     LL extra=DP(0);
                     printf("Case %d: %lld\n",cs,total_C+extra,extra);


              }

       }
   return 0;
}
