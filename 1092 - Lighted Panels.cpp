
//BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopner soman boro
 all my suceesses are dedicated to my parents
 Author :: Shakil Ahmed
.............AUST_CSE27.........
 prob   ::
 Type   ::
 verdict::
 Special thanx to Ahmed Faiyaz vai :D
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
const int INF = 1 << 29 ;
int vis[9][ ( 1 << 8 ) + 10 ][ ( 1 << 8 ) + 10 ] , cs ;
int dp[9][ ( 1 << 8 ) + 10 ][ ( 1 << 8 ) + 10 ];
int sv[9] , r , c ;
char str[10];
int DP( int idx , int curmask , int prvmask )
{
    if( idx >= r )
    {
        if( prvmask == ( 1 << c ) - 1 ) return 0 ;
        else return INF ;
    }
    int &v = vis[idx][curmask][prvmask];
    int &ret = dp[idx][curmask][prvmask];
    if( v == cs ) return ret ;
  //  printf(" here \n");
    ret = INF ;
    for( int i = 0 ; i < ( 1 << c ); i++ )
    {
        int cnt = 0 ;
        int row[3] = {prvmask , curmask , sv[idx+1] };
        for ( int j = 0 ; j < c ; j++ )
        {
            if( !(i & ( 1 << j )) )  continue ;
            // need to toggle
            cnt++;
            rep( k , 3 ) row[k] ^= ( 1 << j );
            if( j  + 1 < c ) rep ( k , 3 ) row[k] ^= ( 1 << ( j + 1 ) );
            if( j - 1 >= 0 ) rep ( k , 3 ) row[k] ^= ( 1 << ( j - 1 ) );

        }
        if( idx == 0 ) ret = min( ret , cnt + DP( idx + 1 , row[2] , row[1] ) );
        else if( row[0] == ( 1 << c ) - 1 )
        ret = min( ret , cnt + DP( idx + 1 , row[2] , row[1] ) );
    }
    return ret ;
}
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
    int t = II ;
    for ( cs = 1 ; cs <= t ; cs++ )
    {
        r = II , c = II ;
        ms( sv ,  0 );
        rep( i , r )
        {
            scanf("%s",str);
            int mask = 0 ;
            rep( j , c )
            {
                if( str[j] == '*' ) mask |= ( 1 << j );
            }
            sv[i] = mask ;
        }
        int ans = DP( 0 , sv[0] , 0 );
        if( ans == INF ) printf("Case %d: impossible\n",cs);
        else printf("Case %d: %d\n",cs,ans);
    }

    return 0;
}
