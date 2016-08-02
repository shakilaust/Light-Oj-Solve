
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
int Mark[25][25],Right[405],h,w,n;
int dx[]={1,-1,0,0,1,1,-1,-1};
int dy[]={0,0,1,-1,-1,1,-1,1};
bool seen[405];
vector <int> adj[405];
char G[25][25];
void CLR()
{
       int i;
       for(i=0;i<n;i++) adj[i].clear();
}
bool check(int x,int y)
{
       if(x<0 || x>=h || y<0 || y>=w) return 0;
       return 1;
}
bool bmp(int u)
{
       int i;
       for(i=0;i<adj[u].size();i++)
       {
              int v=adj[u][i];
              if(seen[v]) continue;
              seen[v]=1;
              if(Right[v]==-1 || bmp(Right[v]))
              {
                     Right[v]=u;
                     return 1;
              }
       }
       return 0;
}
int solve()
{
       int ans=0,i;
       memo(Right,-1);
       for(i=1;i<n;i++)
       {
              memo(seen,0);
              if(bmp(i)) ans+=1;
       }
       return ans/2;
}
int main()
{

    //freopen("in.txt", "r", stdin);
    int cs,t,i,j;
    scanf("%d",&t);
    for(cs=1;cs<=t;cs++)
    {
           scanf("%d %d",&h,&w);
           for(i=0;i<h;i++) scanf("%s",G[i]);
           n=1;
           memo(Mark,0);
           for(i=0;i<h;i++)
           {
                  for(j=0;j<w;j++)
                  {
                         if(G[i][j]=='*')
                         {
                                Mark[i][j]=n++;
                         }
                  }
           }
           CLR();
           for(i=0;i<h;i++)
           {

                  for(j=0;j<w;j++)
                  {
                         if(Mark[i][j])
                         {
                                int x=i;
                                int y=j;
                                int k;
                                rep(k,4)
                                {
                                       int nx=x+dx[k];
                                       int ny=y+dy[k];
                                       if(check(nx,ny) && Mark[nx][ny])
                                       {
                                              adj[Mark[x][y]].pb(Mark[nx][ny]);
                                       }
                                }
                         }
                  }
           }
           printf("Case %d: %d\n",cs,n-solve()-1);

    }


}
