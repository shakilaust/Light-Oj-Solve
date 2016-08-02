
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
#define MAX 100005
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

map <string,int> M;
bool flag;
vector <int> G[MAX];
int color[MAX];
void topo(int u)
{
      color[u]=1;
      int i,sz=G[u].size();
      for(i=0;i<sz;i++)
      {      int v=G[u][i];
             if(!color[v]) topo(v);
             if(color[v]==1)
             {
                    flag=true;
                    return;
             }
      }
      color[u]=2;
}

int main()
{

    //freopen("in.txt", "r", stdin);
    int cs,T,m,i,cnt;
    scanf("%d",&T);
    for(cs=1;cs<=T;cs++)
    {
           scanf("%d",&m);
           M.clear();
           cnt=1;
           while(m--)
           {
                  string a,b;
                  cin>>a>>b;
                  if(!M[a]) M[a]=cnt++;
                  if(!M[b]) M[b]=cnt++;
                  G[M[a]].pb(M[b]);

           }
           for(i=1;i<cnt;++i) color[i]=0;
           flag=false;
           for(i=1;i<cnt;i++)
           {
                  if(!color[i]) topo(i);
                  if(flag) break;
           }
           if(flag) printf("Case %d: No\n",cs);
           else printf("Case %d: Yes\n",cs);
           for(i=1;i<cnt;i++) G[i].clear();

    }



}
