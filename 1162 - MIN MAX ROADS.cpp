
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
template <class T> inline T bigmod(T p,T e,T M)
{
    if(e==0)return 1;
    if(e%2==0){LL t=bigmod(p,e/2,M);return (T)((t*t)%M);}
    return (T)((LL)bigmod(p,e-1,M)*(LL)p)%M;
}

template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}
//Fast Reader
template<class T>inline bool read(T &x){int c=getchar();int sgn=1;while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}for(x=0;~c&&'0'<=c&&c<='9';c=getchar())x=x*10+c-'0'; x*=sgn; return ~c;}

/* **************************************  My code start here ****************************************** */
const int maxn = 100005;
typedef long long ll ;
typedef pair < ll , ll > pll ;
pll res ;
ll maxnl[maxn][20] , minl[maxn][20] , Level[maxn] , parnt[maxn][20];
vector < pll > Adj[maxn];
bool vis[maxn];
ll maxAns , minAns ;
void Dfs(int to , int from , int lvl , ll dist)
{
    Level[to] = lvl ;
    parnt[to][0] = from ;
   // cout << dist << " print " << endl ;
    maxnl[to][0] = dist ;
    minl[to][0] = dist ;
    int i , sz = Adj[to].size();
    int  u ;
    vis[to] = 1;
    for ( i = 0 ; i < sz ; i++ )
    {
        u = Adj[to][i].first;
        if( vis[u]) continue;
        Dfs(u , to , lvl + 1 , Adj[to][i].second);
    }
}
void Preprocess(int n)
{
    int i , j ;
    for ( i = 0 ; i < n ; i++ )
    {
        for ( j = 0 ; ( 1 << j ) < n ; j++ )
        {
            parnt[i][j] = -1 ;
            maxnl[i][j] = -maxn ;
            minl[i][j] = maxn ;// 1e5 highest limit so it will work fine
            vis[i] = 0 ;
        }
    }
    Dfs(0,-1,0,0);
    for ( j = 1 ; ( 1 << j ) < n ; j++ )
    {
        for ( i = 0 ; i < n ; i++ )
        {
            if ( parnt[i][j-1] != -1 )
            {
                parnt[i][j] = parnt[parnt[i][j-1]][j-1];
                maxnl[i][j] = max ( maxnl[i][j-1] , maxnl[parnt[i][j-1]][j-1]);
                minl[i][j] = min(minl[i][j-1] , minl[parnt[i][j-1]][j-1]);
            }
        }
    }

}
void LCA(int a , int b , int n)
{
    if( Level[a] < Level[b] ) swap(a,b) ;
    int logn = 1 ;
    for (  ; (1 << logn) <= Level[a] ; logn++ ) ;
    logn--;
    int i , j ;
    maxAns = -maxn , minAns = maxn ;
    for ( i = logn ; i >= 0 ; i-- )
    {
        if ( Level[a] - ( 1 << i ) >= Level[b] )
        {

            minAns = min(minAns, minl[a][i]);
            maxAns = max(maxAns , maxnl[a][i]);
            a = parnt[a][i] ;
        }
    }
    if( a == b ) return ;
    for ( i = logn ; i >= 0 ; i-- )
    {
        if (parnt[a][i] != -1 && parnt[a][i] != parnt[b][i] )
        {

            minAns = min( minAns , min(minl[b][i],minl[a][i]));
            maxAns = max( maxAns , max(maxnl[b][i],maxnl[a][i]));
            a = parnt[a][i] ;
            b = parnt[b][i];
        }
    }
     minAns = min(minAns , min(minl[b][0],minl[a][0]));
     maxAns = max(maxAns , max(maxnl[b][0],maxnl[a][0]));

}
int main()
{
  // freopen("input.txt","r",stdin);
     //freopen("output.txt","w",stdout);
     int cs , t ;
     read(t) ;
     for ( cs = 1 ; cs <= t ; cs++ )
     {
         int n , q , u , v , w , i;
         read(n) ;
         for ( i = 0 ; i < n - 1 ; i++ )
         {
             read(u) , read(v) , read(w) ;
             u-- , v-- ;
             Adj[u].pb(mp(v,w));
             Adj[v].pb(mp(u,w));
         }
         Preprocess(n);
         read(q);
         printf("Case %d:\n",cs);
         for ( i = 0 ; i < q ; i++ )
         {
             read(u) , read(w) ;
             u-- , w-- ;
             LCA(u,w,n);
             printf("%lld %lld\n",minAns,maxAns);
         }
         for ( i = 0 ; i < n ; i++ ) Adj[i].clear();
     }
   return 0;
}
/*
2

6
3 6 50
2 5 30
2 4 300
1 2 100
1 3 200
5
3 5
1 4
4 6
2 5
3 5

2
1 2 100
1
1 2
*/
