
//BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopner soman boro
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
#define FO freopen ("2.txt", "w", stdout)

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

int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

/* **************************************  My code start here ****************************************** */
const int NX = 17 ;
const int INF = 1 << 29 ;
int dp[ 1 << NX ] ;
int inp[ NX ] , n , w , k ;
int sv[ NX ][ NX ] ;
int point[NX][2]  ;

bool yes( int x1 , int y1 , int x2 , int y2 , int x3 , int y3 )
{
  double total = ( x1 * ( y2 - y3 ) + x2 * ( y3 - y1 ) + x3 * ( y1 - y2 ) );
  return total/2.0 == 0.0 ? 1 : 0 ;
}
int DP( int mask )
{
    if( mask == ( 1 << n ) - 1 ) return 0 ;
    int  &ret = dp[mask];
    if( ret != -1 ) return ret ;
    ret = 0 ;
    int i , j , pos  ;
    rep( i , n )
    {
        if( mask & 1 << i ) continue ;
        ret++;
        pos = i ;

    }
    i = pos ;

        rep ( j , n )
        {
            if( i == j || mask & ( 1 << j ) ) continue ;
            ret = min( ret , DP ( mask | sv[i][j] ) + 1 );

        }

    return ret ;
}
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
   int cs , t = II ;
   for ( cs = 1 ; cs <= t ; cs++ )
   {
       n = II ;
       rep ( i , n )
       {
           point[i][0] = II , point[i][1] = II ;
       }
       int i , j , k ;
       ms( sv , 0 );
       rep( i , n )
       {
           rep( j , n )
           {
               if( i == j ) continue ;
               sv[i][j] |= ( 1 << i );
               sv[i][j] |= ( 1 << j );
               rep( k , n )
               {
                   if( i == k || j == k ) continue ;
                   if( yes( point[i][0] , point[i][1] , point[j][0] , point[j][1] , point[k][0] , point[k][1]))
                    sv[i][j] |= ( 1 << k );
               }
           }
       }
       ms( dp , -1 );
       printf("Case %d: %d\n",cs,DP(0));

   }

    return 0;
}
