
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
int cs  , vis[16][16][16][16][6][6];
double dp[16][16][16][16][6][6] ;
int a[5];
double DP( int club , int dice , int hearts , int spades , int j1 , int j2 )
{
    int c = ( 13 - club ) + ( j1 == 1 ) + ( j2 == 1 );
    int d = ( 13 - dice ) + ( j1 == 2 ) + ( j2 == 2 );
    int h = ( 13 - hearts ) + ( j1 == 3 ) + ( j2 == 3 );
    int s = ( 13 - spades ) + ( j1 == 4 ) + ( j2 == 4 );
    double tot = club + dice + hearts + spades + ( j1 == 0 ) + ( j2 == 0 );
    if( c >= a[0] && d >= a[1] && h >= a[2] && s >= a[3] ) return 0.00 ;
    if( club + dice + hearts + spades + !j1 + !j2  == 0 ) return 10000000.000 ;
    int &v = vis[club][dice][hearts][spades][j1][j2];
    if( v == cs ) return dp[club][dice][hearts][spades][j1][j2];
    v = cs ;
    double ret = 0 ;
    if(club )  ret += ( club / tot ) * ( 1 + DP( club - 1 , dice , hearts , spades , j1 , j2 ) );
    if(dice )  ret += ( dice / tot ) * ( 1 + DP( club , dice - 1 , hearts , spades , j1 , j2 ) );
    if(hearts) ret += ( hearts / tot ) *( 1+ DP( club , dice , hearts - 1 , spades , j1 , j2 ) );
    if(spades) ret += ( spades / tot ) *(1 + DP( club , dice , hearts , spades - 1 , j1 , j2 ) );
    double joker = ( j1 == 0 ) + ( j2 == 0 );
    double ans , tmp ;
    if( j1 == 0 )
    {

        ans = ( joker / tot ) * ( 1 + DP( club , dice , hearts , spades , 1 , j2 ) );
        tmp = ( joker / tot ) * ( 1 + DP( club , dice , hearts , spades , 2 , j2 ) );
        if( tmp < ans ) ans = tmp ;
        tmp = ( joker / tot ) * ( 1 + DP(club , dice , hearts , spades , 3 , j2 ) );
        if( tmp < ans ) ans = tmp ;
        tmp = ( joker / tot ) * ( 1 + DP( club , dice , hearts , spades , 4 , j2 ) );
        if( tmp < ans ) ans = tmp ;
        ret += ans ;
    }
    else if( j2 == 0 )
    {
        ans = ( joker / tot ) * ( 1 + DP( club , dice , hearts , spades , j1 , 1  ) );
        tmp = ( joker / tot ) * ( 1 + DP( club , dice , hearts , spades ,j1 ,  2  ) );
        if( tmp < ans ) ans = tmp ;
        tmp = ( joker / tot ) * ( 1 + DP(club , dice , hearts , spades , j1 , 3 ) );
        if( tmp < ans ) ans = tmp ;
        tmp = ( joker / tot ) * ( 1 + DP( club , dice , hearts , spades , j1 ,  4  ) );
        if( tmp < ans ) ans = tmp ;
        ret += ans ;
    }
    return dp[club][dice][hearts][spades][j1][j2] = ret ;
}
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
   cout << fixed << setprecision(10) ;
    int t = II ;
    for ( cs = 1 ; cs <= t ; cs++ )
    {

        int ex = 0 ;
        rep( i , 4 )
        {
            a[i] = II ;
            if( a[i] > 13 ) ex += ( a[i] - 13 );
        }
        printf("Case %d: ",cs);
        if( ex > 2 ) printf("-1\n");
        else
        {
            double res = DP( 13 , 13 , 13 , 13 , 0 , 0 );
            cout << res << endl ;
        }


    }

    return 0;
}
