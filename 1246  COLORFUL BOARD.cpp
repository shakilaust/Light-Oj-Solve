
//BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopner soman boro
 all my suceesses are dedicated to my parents
 Author :: Shakil Ahmed
.............AUST_CSE27.........
 prob   ::
 Type   ::
 verdict::
 Thanks a lot to my very special friend Roberto Sales :)
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
const int NX = 2005 ;
const int MX = 1005 ;
const int mod = 1000000007 ;
int ncr[MX][MX] , dp[NX][ 55 ] , pw[ 55 ][MX] , n , k  , m ;
int C[MX][MX];
void ini()
{
    int i , j ;
    for ( i = 0 ; i < MX ; i++ )
    {
        for ( j = 0 ; j <= i; j++ )
        {
            if( i == 0 || j == i ) ncr[i][j] = 1 ;
            else ncr[i][j] = ( ncr[i-1][j-1] + ncr[i-1][j])%mod ;
        }
    }

}


    int power(int n, int p){
        if(p == 0) return 1;
        if(p == 1) return n;
        if(pw[n][p]) return pw[n][p];

        return pw[n][p] = ((Long) power(n, p-1) * n) % mod ;
    }

int DP( int cells , int colors )
{
    if( colors > cells || cells == 0 || colors == 0 ) return 0 ;
    if( colors == 1 ) return 1 ;
    int &ret = dp[ cells ][ colors ];
    if( ret != -1 ) return ret ;
    ret = 0 ;
    int i ;
    for ( i = 1 ; i <= cells ; i++ )
    {
        ret = ( ( Long ) ncr[ cells ][ i ] * DP ( cells - i , colors - 1 ) + ret )% mod ;
    }
    return ret ;
}

int solve( int kl , int lft )
{
    if( lft <= 0 ) return 0 ;
    int x = ( n * m )/2 ;
    int y = ( n * m + 1 ) / 2 ;
    if( x < kl ) return 0 ;
    int ans = (( Long ) DP( x , kl ) * power( lft , y ) ) % mod;
   // ans %= mod ;
    ans = ( ( Long ) ans * ncr[ k ][ kl ]) % mod ;
   // ans %= mod ;
    return ans ;
}

int Ans()
{
    int i ;
    n = II , m = II , k = II ;
    n++ , m++ ;
    if( n == 1 && m == 1 ) return k ;
    int ans = 0 ;
    for ( i = 1 ; i < k ; i++ )
    {
        ans = (solve( i , k - i ) + ans )%mod;
    }
    return ans ;
}
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
       //cout << ( 1 << 30 ) << endl ;
     ini();
     int cs , t = II ;
     ms( dp , -1 );

     for ( cs = 1 ; cs <= t ; cs++ )
     {
         printf("Case %d: %d\n",cs,Ans());
     }
    return 0;
}
