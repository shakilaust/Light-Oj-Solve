
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <utility>


#define pb push_back
#define mp make_pair
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

const int NX = 30 ;
const int MX = 950 ;

Long dp[NX][MX] ;
int T[NX][MX] , needPass[NX] , Hasfish[NX] , kombe[NX] , n , h ;
int vis[NX][MX] , cs ;

Long DP( int now , int left )
{


    if( now == n || left <= 0 ) return 0 ;
    int &v = vis[now][left] ;
    Long &ret = dp[now][left];
    if( v == cs ) return ret ;
    v = cs ;
    ret = DP( now + 1 , left  - ( needPass[now] ) );
    T[now][left] = 0 ;
    int i , k ;
    int sum = 0 , Dec = 0 ;
    for ( i = 1 , k = 1 ; i <= left ; i ++ , k++ , Dec += kombe[now] )
    {
        sum += max(Hasfish[now] - Dec , 0 );
        int tt = i;
        Long tmp = DP( now + 1 , left - tt - ( needPass[now] )) + sum ;
        if( tmp >= ret )
        {
            ret = tmp ;
            T[now][left] = tt ;
        }

    }
    return ret ;
}
void print( int now , int left)
{
    if( now == n )
    {
        puts("");
        return ;
    }
    if ( now ) printf(", ");
    if( left <= 0 )
    {
        printf("0");
        print(now + 1 , 0 );
    }
    else
    {
        printf("%d",T[now][left] * 5);
        print( now + 1 , left - T[now][left] - (  needPass[now]));
    }
}
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
  // cout << fixed << setprecision(10) ;
    int t = II ;
    for ( cs = 1 ; cs <= t ; cs++ )
    {
        n = II , h = II ;
        rep( i , n ) Hasfish[i] = II ;
        rep( i , n ) kombe[i] = II ;
        rep( i , n - 1 ) needPass[i] = II ;
        needPass[n-1] = 0 ;
        Long ans = DP(  0 , h * 12 );
        printf("Case %d:\n",cs);
        print(0,h*12);
        printf("Number of fish expected: %lld\n",ans);
    }

    return 0;
}
