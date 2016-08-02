
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

const int NX = 52 ;
const Long mod = 1000000007;
Long dp[NX][NX][NX][2];
int k , n , vis[NX][NX][NX][2] , tt ;
Long ans[NX][NX];
Long DP( int Small , int Big , int Cur , int found )
{
    if( Cur == k ) found = 1 ;
    if( Cur > k ) return 0 ;
    if( Small + Big == 0 ) return (found );
    int &v = vis[Small][Big][Cur][found];
    Long &ret = dp[Small][Big][Cur][found];
    if( v == tt ) return ret ;
    v = tt ;
    ret = 0 ;
    int i ;
    // Placing Small number
    for ( i = 1 ; i <= Small ; i++ ) { ret += DP( i - 1 , Small + Big - i , 1 , found );
    ret %= mod ; }
    // placing Big numbe

    if( Cur != k )
    for( i = 1 ; i <= Big ; i++ ) {
    ret += DP( Small + i - 1 , Big - i , Cur + 1 , found );
    ret %= mod ;
    }
    return ret ;

}

void pre()
{
    for( k = 1 , tt = 1 ; k <= 50 ; k++ , tt++ )
    {
        for( n = k ; n <= 50 ; n++ )
        {
            ans[n][k] = DP( 0 , n , 0 , 0 );
        }
    }
}
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
   pre();
   int cs , t = II ;
   for ( cs = 1 ; cs <= t ; cs++ )
   {
       n = II , k = II ;
       printf("Case %d: %lld\n",cs,ans[n][k]);
   }


    return 0;
}
