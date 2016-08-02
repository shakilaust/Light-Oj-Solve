
 //BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopner soman boro
 Author :: Shakil Ahmed
.............AUST_CSE27.........
 prob   ::  Loj 1251
 Type   ::  2 set
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
#define MAX (2*8000+5)
#define MOD
#define INF 1<<30
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define memo(a,b) memset((a),(b),sizeof(a))
#define G() getchar()


using namespace std;


template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
vector <int> adj[MAX],rev[MAX],order,res;
int comp[MAX],n,m;
bool vis[MAX];

int value(int x)
{
         if ( x < 0 ){
        x=-x;
        x--;
        return ((x)<<1)+1;
    }
    x--;
    return ((x)<<1);

}
void topo(int u)
{      vis[u]=1;
       int i;
       for(i=0;i<adj[u].size();i++)
       {
              int v=adj[u][i];
              if(!vis[v]) topo(v);
       }
       order.pb(u);
}
void scc(int u,int col)
{
       comp[u]=col;
       int i;
       for(i=0;i<rev[u].size();i++)
       {
              int v=rev[u][i];
              if(comp[v]==-1)
              {
                     scc(v,col);
              }
       }
}

bool twosat()
{
       int i;
       /*printf("n:: %d\n",n);
       for(i=0;i<2*n;i++)
       printf("comp[%d]:: %d\n",i,comp[i]); */
       for(i=0;i<2*n;i+=2)
         if(comp[i]==comp[i+1]) return false;
       return true;
}
int main()
{

    //freopen("in.txt", "r", stdin);
    int cs,t,i;
    scanf("%d",&t);
    //getchar();
   // printf("t::%d\n",t);
    for(cs=1;cs<=t;cs++)
    {
           scanf("%d %d",&m,&n);
         //  printf("m::%d n:: %d\n",m,n);
           for(i=0;i<=2*n+1;i++)
           {      vis[i]=0;
                  comp[i]=-1;
                  adj[i].clear();
                  rev[i].clear();
           }
           while(m--)
           {
                  int x,y;
                  scanf("%d %d",&x,&y);
                //  printf("x::%d y::%d\n",x,y);
                  //  x--,y--;
                  x=value(x);
                  y=value(y);
                  adj[x^1].pb(y);
                  adj[y^1].pb(x);

                  rev[x].pb(y^1);
                  rev[y].pb(x^1);
           }
           order.clear();
           for(i=0;i<2*n;i++) if(!vis[i]) topo(i);
           int cnt=0;
           reverse(order.begin(),order.end());
           for(i=0;i<order.size();i++)
              if(comp[order[i]]==-1)  scc(order[i],cnt++);
          if(!twosat())
          {
                printf("Case %d: No\n",cs);
          }
          else
          {
                 res.clear();
                 printf("Case %d: Yes\n",cs);
                 for(i=0;i<2*n;i+=2)
                     if(comp[i]>comp[i+1]) res.pb(i/2);
                 printf("%d",res.size());
                 for(i=0;i<res.size();++i) printf(" %d",res[i]+1);
                 puts("");

          }

    }



}
