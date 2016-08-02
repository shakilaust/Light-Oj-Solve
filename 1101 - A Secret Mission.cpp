
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
const int maxn = 100005 ;
int n , m , parnt[maxn] , P[maxn][20] , maxE[maxn][20] , Level[maxn];
int find_parnt(int x )
{
    if ( parnt[x] == x ) return x ;
    else return parnt[x] = find_parnt(parnt[x]);
}
vector < pii > adj[maxn];
struct abc
{
    int u , v , c ;
}edge[maxn];

bool cmp(abc A , abc B )
{
    return A.c < B.c ;
}
void MST()
{
    //printf("here :: m :: %d \n", m);
    sort(edge,edge+m ,cmp);
    int i , j , U , V , C;
    int ed = 0;
    for ( i = 0 ; i <= n ; i++ ) parnt[i] = i ;
    for ( i = 0 ; i < m && ed < n-1; i++ )
    {

        U = edge[i].u ;
        V = edge[i].v ;
        C = edge[i].c ;
        int nx = find_parnt(U);
        int ny = find_parnt(V);
        //printf("nx :: %d ny :: %d\n", nx , ny );
        if(nx != ny)
        {   ed++;
            parnt[nx] = ny ;
           // printf(" %d - > %d with cost %d\n", U , V , C);
            adj[U].pb(mp(V,C));
            adj[V].pb(mp(U,C));
        }
    }
}
void dfs(int to , int from , int lvl , int dist )
{
    maxE[to][0] = dist ;
    Level[to] = lvl ;
    P[to][0] = from ;
    int sz = adj[to].size();
    int i , u ;
    for ( i = 0 ; i < sz ; i++ )
    {
        u = adj[to][i].first;
        if( u == from ) continue;
        dfs(u,to,lvl+1,adj[to][i].second);
    }
}
void Preposs()
{
    int i , j ;
    for ( i = 0 ; i < n ; i++ )
    {
        for ( j = 0 ; ( 1 << j ) < n ; j++ )
        {
            P[i][j] = -1 ;
            maxE[i][j] = -1;
        }
    }
    dfs(0,-1,0,0);
    for ( j = 1 ; ( 1 << j ) < n ; j++ )
    {
        for ( i = 0 ; i < n ; i++ )
        {
            if(P[i][j-1] != -1 )
            {
                P[i][j] = P[P[i][j-1]][j-1];
                maxE[i][j] = max(maxE[i][j-1] , maxE[P[i][j-1]][j-1]);
            }
        }
    }
}
int LCA(int a , int b)
{
    if ( Level[a] < Level[b] ) swap(a,b);
    int logn , i , j , ans = -1 ;
    for ( logn = 1 ; ( 1 << logn ) <= Level[a] ; logn++ ) ;
    logn--;
    for ( i = logn ; i >= 0  ; i-- )
    {
        if ( Level[a] - ( 1 << i ) >= Level[b] )
        {
            ans = max( ans , maxE[a][i] );
            a = P[a][i] ;
        }
    }
    if( a == b ) return ans ;
    for ( i = logn ; i >= 0 ; i-- )
    {
        if ( P[a][i] != -1 && P[a][i] != P[b][i] )
        {
            ans = max( ans , max(maxE[a][i] , maxE[b][i]));
            a = P[a][i] ;
            b = P[b][i];
        }
    }
     ans = max( ans , max(maxE[a][0] , maxE[b][0]));
     return ans;

}
int main()
{
  // freopen("input.txt","r",stdin);
     //freopen("output.txt","w",stdout);
     int cs , t , q , i , u , v , c ;
     read(t);
     for ( cs = 1 ; cs <= t ; cs++ )
     {
         read(n) , read(m) ;
         for ( i = 0 ; i < m ; i++ )
         {
             read(u) , read(v) , read(c);
             u--;
             v--;
             edge[i].u = u ;
             edge[i].v = v ;
             edge[i].c = c ;
         }
         MST();
         Preposs();
         read(q);
         printf("Case %d:\n",cs);
         while(q--)
         {
             read(u) , read(v) ;
             u-- , v-- ;
             printf("%d\n",LCA(u,v));
         }
         if( cs != t )
         for ( i = 0 ; i < n ; i++ ) adj[i].clear();
     }
   return 0;
}
