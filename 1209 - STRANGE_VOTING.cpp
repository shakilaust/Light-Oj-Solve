
 //BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopner soman boro
 Author :: Shakil Ahmed
.............AUST_CSE27.........
 prob   :: uva 12168
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

vector <int> adj[505];
int Right[505];
struct abc
{
       int x,y;
}cat[505],dog[505];
bool seen[505];
int n,m,V,IdxC,IdxD;
void Clear()
{
       int i;
       for(i=0;i<505;i++)
       {

              adj[i].clear();
       }

}
void CLR()
{
       int i;
       for(i=0;i<IdxD;i++) seen[i]=0;
}
bool kuhn(int u)
{
       int i;
       for(i=0;i<adj[u].size();i++)
       {
              int v=adj[u][i];
              if(seen[v]) continue;
              seen[v]=1;
              if(Right[v]==-1 || kuhn(Right[v]))
              {
                     Right[v]=u;
                     return 1;
              }
       }
  return 0;
}
int solve()
{
       int i,ans=0;
       for(i=0;i<IdxD;i++) Right[i]=-1;
       for(i=0;i<IdxC;i++)
       {
               CLR();
              if(kuhn(i)) ans+=1;
       }
       return ans;
}
int main()
{

    //freopen("in.txt", "r", stdin);
    int cs,t;
    cin>>t;
    rep(cs,t)
    {
           cin>>n>>m>>V;
           Clear();
           IdxC=IdxD=0;
           int i,X,Y,j;
           char c1,c2;
           for(i=1;i<=V;i++)
           {
                  cin>>c1>>X>>c2>>Y;
                  if(c1=='M')
                  {
                         cat[IdxC].x=X;
                         cat[IdxC++].y=Y;
                  }
                  else
                  {
                         dog[IdxD].x=X;
                         dog[IdxD++].y=Y;

                  }
           }
           for(i=0;i<IdxC;i++)
           {
                  for(j=0;j<IdxD;j++)
                  {
                         if(cat[i].y==dog[j].x || dog[j].y==cat[i].x)
                         {
                                adj[i].pb(j);
                         }
                  }
           }
           printf("Case %d: ",cs+1);
           cout<<V-solve()<<endl;
    }


}
/*
1
1 2 4
C1 D1
C2 D1
D1 C1
D1 C2
 */
