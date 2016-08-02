
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
const int NX = 82 ;

int dp[ 10 ][ NX ][ NX ][ 2 ] , cs , vis[ 10 ][ NX ][ NX ][ 2 ] , len , inp[ 12 ];
int k , tt , a , b ;
int DP( int pos , int rem , int remdigit , int isSmall )
{
    if( pos == len ) return !( rem + remdigit);
    int &v = vis[pos][rem][remdigit][isSmall];
    int &ret = dp[pos][rem][remdigit][isSmall];
    if( v == tt ) return ret ;
    v = tt ;
    ret = 0 ;
    int mx = isSmall ? 9 : inp[pos];
    rep( i , mx ) ret += DP( pos + 1 , ( rem*10 + i )%k , (remdigit + i)%k , 1 );
    if(isSmall) ret += DP( pos + 1 , ( rem*10 + mx)%k , (remdigit + mx)%k , 1 );
    else ret += DP( pos + 1 , ( rem*10 + mx)%k , (remdigit + mx)%k , 0 );

    return ret ;

}

int solve( int num)
{
    len = 0 ;
    while(num > 0 )
    {
        inp[len++] = num%10;
        num/=10;
    }
    reverse( inp , inp + len );

    tt++;
    return DP( 0 , 0 , 0 , 0 );

}
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
    int cs , t = II ;
    for ( cs = 1 ; cs <= t ; cs++ )
    {

             a  = II , b = II , k = II ;
             if( a > b ) swap( a , b );
             printf("Case %d: ", cs);
             if( k == 1 ) printf("%d\n",b-a+1);
             else if( k > 81 ) printf("0\n");
             else
             {
                 int ans = solve(b);
                 ans -= solve(a-1);
                 printf("%d\n",ans);
             }

    }
    return 0;
}
