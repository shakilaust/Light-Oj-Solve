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
const int INF = 1 << 29  ;
int cs , dp[ 1 << 17 ][22] , vis [ 1 << NX ][22] ;
int dis[NX][NX] , idx , pos[NX][2] ;
char str[22][22];

int DP( int mask , int pos )
{
    if( mask == ( 1 << idx ) - 1 ) return dis[pos][0];
    int &ret = dp[mask][pos];
    if( vis[mask][pos] == cs ) return ret ;
    vis[mask][pos] = cs ;
    ret = INF ;
    int i ;
    for( i = 0 ; i < idx ; i++ )
    {
        if( mask & 1 << i ) continue ;
        int now = dis[pos][i] + DP( mask | ( 1 << i ) , i );
        ret = min( ret , now );
    }
    return ret ;
}
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
   int t ;
   scanf("%d",&t);
   for( cs = 1 ; cs <= t ; cs++ )
   {

       int n = II , m = II ;
       rep( i , n )
       {
           scanf("%s",str[i]);
           rep( j , m ) if( str[i][j] == 'x' )
           {
               pos[0][0] = i ;
               pos[0][1] = j ;
           }
       }
       idx = 1 ;
       rep( i , n )
       {
           rep( j , m ) if( str[i][j] == 'g' )
           {
               pos[idx][0] = i ;
               pos[idx++][1] = j ;
           }
       }
       rep( i , idx)
       {
           rep( j , idx  )
           {
               dis[i][j] = dis[j][i] = max( abs( pos[i][0] - pos[j][0]) , abs( pos[i][1] - pos[j][1] ));
           }
       }
       printf("Case %d: %d\n",cs,DP(1,0));

   }

    return 0;
}
