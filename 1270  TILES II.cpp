
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
const int NX = ( 1 << 8 ) + 10 ;
const int MX = 105 ;
ull dp[MX][NX] ;
int vis[MX][NX] , cs , row , col ;
char inp[MX][MX] , grid[MX][MX] ;
ull DP(int , int) ;
ull gen( int r , int c , int curmask , int nxtmask )
{
    if( c == col ) return DP( r + 1 , nxtmask );
    int cc = ( curmask >> c ) & 1 ;
    int cnc = ( curmask >> ( c + 1 ) ) & 1 ;
    int nc = ( nxtmask >> ( c ) ) & 1 ;
    int nnc = ( nxtmask >> ( c + 1 ) ) & 1 ;
    int npc = ( nxtmask >> max( 0 , c -1 ) ) & 1 ;
    if( cc ) return gen( r , c + 1 , curmask , nxtmask );
    if( grid[r][c] == '#' ) return gen( r , c + 1 , curmask , nxtmask );
    ull ret = 0 ;
    // title one
    if( r + 1 < row )
    {
        if( grid[r][c] == '.' && grid[r+1][c] == '.' && !cc && !nc )
        {
            ret += gen( r , c + 1 , curmask | ( 1 << c ) , nxtmask | ( 1 << c ) );
        }
    }
    // tile two
    if( c + 1 < col )
    {
        if( grid[r][c] == '.' && grid[r][c+1] == '.' && !cc && !cnc )
        {
            ret += gen( r , c + 2 , curmask | ( 1 << c ) | ( 1 << ( c + 1 ) ) , nxtmask );
        }
    }
    // tile five
    if( c - 1 >= 0 && r + 1 < row )
    {
        if( grid[r][c] == '.' && grid[r+1][c] == '.' && grid[r+1][c-1] == '.' && !cc && !nc && !npc )
        {
            ret += gen( r , c + 1 , curmask | ( 1 << c ) , nxtmask | ( 1 << c) | ( 1 << ( c - 1 ) ) );
        }
    }
    if( r + 1 < row  && c + 1  < col )
    {
        // tile 4
         if( grid[r][c] == '.' && grid[r][c+1] == '.' && grid[r+1][c] == '.' && !cc && !cnc && !nc )
        {
            ret += gen( r , c + 1 , curmask | ( 1 << c ) | ( 1 << ( c + 1 ) ), nxtmask | ( 1 << c) );
        }
        // tile 3
         if( grid[r][c] == '.' && grid[r+1][c] == '.' && grid[r+1][c+1] == '.' && !cc && !nc && !nnc )
        {
            ret += gen( r , c + 1 , curmask | ( 1 << c ) , nxtmask | ( 1 << c) | ( 1 << ( c + 1 ) ) );
        }
        // tile 6
         if( grid[r][c] == '.' && grid[r][c+1] == '.' && grid[r+1][c+1] == '.' && !cc && !cnc && !nnc )
        {
            ret += gen( r , c + 1 , curmask | ( 1 << c ) | ( 1 << ( c + 1 ) ) , nxtmask |  ( 1 << ( c + 1 ) ) );
        }

    }
    return ret ;

}

ull DP(int r , int mask)
{
    if( r == row ) return mask == 0 ;
    ull &ret = dp[r][mask];
    int &v = vis[r][mask];
    if( v == cs ) return ret ;
    v = cs ;
    ret = gen(r , 0 , mask , 0 );
    return ret ;
}

int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
  // ms( vis , -1 );

     int t = II ;
     for ( cs = 1 ; cs <= t ; cs++ )
     {
         row = II , col = II ;
         rep( i , row ) scanf("%s",inp[i]);
         if( row < col )
         {
             rep( i , row ) rep ( j , col ) grid[j][i] = inp[i][j];
             swap( row , col );
         }
         else
         {
             rep( i , row ) rep ( j , col ) grid[i][j] = inp[i][j];

         }
         printf("Case %d: %llu\n",cs,DP(0,0));
     }




    return 0;
}
