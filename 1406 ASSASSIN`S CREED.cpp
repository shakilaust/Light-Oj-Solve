
//BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopner soman boro
 all my suceesses are dedicated to my parents
 Author :: Shakil Ahmed
.............AUST_CSE27.........
 prob   ::
 Type   ::
 verdict::
 */

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pi acos(-1.0)
#define ff first
#define ss second
#define re return
#define QI queue<int>
#define SI stack<int>
#define SZ(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define ms(a,b) memset((a),(b),sizeof(a))
#define G() getchar()
#define MAX3(a,b,c) max(a,max(b,c))
#define II ( { int a ; read(a) ; a; } )
#define LL ( { Long a ; read(a) ; a; } )
#define DD ({double a; scanf("%lf", &a); a;})

double const EPS=3e-8;
using namespace std;

#define FI freopen ("input.txt", "r", stdin)
#define FO freopen ("output.txt", "w", stdout)

typedef long long Long;
typedef long long int64;
typedef unsigned long long ull;
typedef vector<int> vi ;
typedef set<int> si;
typedef vector<Long>vl;
typedef pair<int,int>pii;
typedef pair<string,int>psi;
typedef pair<Long,Long>pll;
typedef pair<double,double>pdd;
typedef vector<pii> vpii;

// For loop

#define forab(i, a, b)	for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n)		forab (i, 0, (n) - 1)
#define For(i, n)		forab (i, 1, n)
#define rofba(i, a, b)	for (__typeof (b)i = (b) ; i >= a ; --i)
#define per(i, n)		rofba (i, 0, (n) - 1)
#define rof(i, n)		rofba (i, 1, n)
#define forstl(i, s)	for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)

template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }

//Fast Reader
template<class T>inline bool read(T &x){int c=getchar();int sgn=1;while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}for(x=0;~c&&'0'<=c&&c<='9';c=getchar())x=x*10+c-'0'; x*=sgn; return ~c;}

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

/* **************************************  My code start here ****************************************** */
const int  INF = 1 << 29 ;
int sv[20] , dp[ ( 1 << 16 ) + 10 ] , vis[ ( 1 << 16 ) + 10 ] , cs ;
int deg[17] , adj[20][20] , mem[17][ 1 << 17 ] , isPossible[ 1 << 17]  , n , m  ;
int rdeg[17] , rev[20][20];

void dfs( int x , int mask )
{
    mem[x][mask] = 1 ;
    isPossible[mask] = 1 ;
    rep( i , deg[x])
    {
        int u = adj[x][i];
        if( !mem[u][mask|(1 << u)]) dfs( u , mask | ( 1 << u ) );
    }
}
int DP( int mask )
{
    if( mask == 0 ) return 0 ;
    int &v = vis[mask];
    int &ret = dp[mask];
    if( v == cs ) return ret ;
    v = cs ;
    ret = INF ;
    int i ;
    for ( i = mask ; i ; i = ( mask ) & ( i - 1 ) )
    {
        if( isPossible[i] ) ret = min( ret , 1 + DP( mask ^ i ) );
    }
    return ret ;
}
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
    int t = II ;
    for ( cs = 1 ; cs <= t ; cs++)
    {
        n = II , m = II ;
        ms( deg , 0 );
        ms( mem , 0 );
        ms( isPossible , 0 );
        rep( i , m )
        {
            int x = II , y = II ;
            x-- , y--;
            adj[x][deg[x]++] = y ;

        }
        rep( i , n ) dfs( i , 1 << i );


        printf("Case %d: %d\n",cs,DP(( 1 <<  n ) - 1 ));
    }
    return 0;
}
