
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
const int NX = 505 ;
int U[NX][NX] , R[NX][NX] , dp[NX][NX];
int r , c ;
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
   int  t = II , cs;
   for ( cs = 1 ; cs <= t ; cs++ )
   {

         r = II , c = II ;
         rep(  i , r )
         {
             rep( j , c )
             {
                 U[i][j] = II ;
                 if( j ) U[i][j] += U[i][j-1];
             }
         }
         rep( i , r )
         {
             rep( j , c )
             {
                 R[i][j] = II ;
                 if( i ) R[i][j] += R[i-1][j];
             }
         }
         dp[0][0] = max(  R[0][0] , U[0][0] );
         rep( i , c - 1 )
         {
             dp[0][i+1] = max( dp[0][i] + R[0][i + 1] , U[0][i + 1] );
         }
         rep( i , r - 1 )
         {
             dp[i+1][0] = max( dp[i][0] + U[i + 1 ][0] , R[i+1][0] );
         }
         rep( i , r - 1 )
         {
             rep( j , c - 1 )
             {
                 dp[i+1][j+1] = max( dp[i][j] , max( dp[i][j+1] , dp[i+1][j] ) );
                 dp[i+1][j+1] = max( dp[i+1][j+1] , dp[i][j+1] + U[i+1][j+1]);
                 dp[i+1][j+1] = max( dp[i+1][j+1] , dp[i+1][j] + R[i+1][j+1] );
             }
         }
         printf("Case %d: %d\n",cs,dp[r-1][c-1]);

   }

    return 0;
}
