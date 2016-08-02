
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
const int NX = 40  ;
const int INF = 1 << 29 ;
int column[NX] ;
int Lcs[ NX ][ NX ] ;
int vis[ NX ] [ NX ] [ NX ] ;
Long dp[ NX ] [ NX ] [ NX ] ;
int cs ;
char A[ NX ] , B [ NX ] ;
int lena , lenb , len  ;
Long DP( int x , int y , int z )
{
    if( z == len )
    {
        if( x == lena && y == lenb ) return 1 ;
        else return 0 ;
    }
    if( vis[x][y][z] == cs ) return dp[x][y][z];
    vis[x][y][z] = cs ;
    Long &ret = dp[x][y][z];
    ret = 0 ;

    if( y == lenb ) ret += DP( x + 1 , y , z + 1 );
    else if( x == lena ) ret += DP( x , y + 1 , z + 1 );
    else if( A[x] == B[y] ) ret += DP( x + 1, y + 1 , z + 1 );
    else ret += DP( x + 1 , y , z + 1 ) + DP ( x , y + 1 , z + 1 );
    return ret ;
}

int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
    int t = II ;
    for ( cs = 1 ; cs <= t ; cs++ )
    {
       scanf("%s%s",A,B);
       lena = strlen( A );
       lenb = strlen( B );
       int i , j ;
       rep( i , lena + 1 ) rep ( j , lenb + 1 )
       {
           if( !i || !j ) Lcs[i][j] = 0 ;
           else
           {
               if( A[i - 1] == B[ j - 1] ) Lcs[i][j] = Lcs[i-1][j-1] + 1 ;
               else Lcs[i][j] = max( Lcs[i-1][j] , Lcs[i][j-1] );
           }
       }
       len = lena + lenb - Lcs[lena][lenb];
       printf("Case %d: %d %lld\n",cs,len,DP(0,0,0));
    }

    return 0;
}
