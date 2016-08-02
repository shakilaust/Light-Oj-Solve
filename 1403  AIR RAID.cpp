
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
const int N=1005;
int seen[N],Right[N];
vector <int> adj[N];
int n,m;
void CLR()
{
       int i;
       for(i=1;i<=n;i++) adj[i].clear();
}
bool kuhn(int u)
{
       int i,sz=adj[u].size();
       for(i=0;i<sz;i++)
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
       int ans=0,i;
       for(i=1;i<=n;i++) Right[i]=-1;
       for(i=1;i<=n;i++)
       {
              int j;
              for(j=1;j<=n;j++) seen[j]=0;
              if(kuhn(i)) ans+=1;
       }
       return ans;
}
int main()
{

    //freopen("in.txt", "r", stdin);
    int cs,t,i,u,v;
    scanf("%d",&t);
    for(cs=1;cs<=t;cs++)
    {
           scanf("%d %d",&n,&m);
           CLR();
           rep(i,m)
           {
                  scanf("%d %d",&u,&v);
                  adj[u].pb(v);
           }
           printf("Case %d: %d\n",cs,n-solve());


    }


}
