

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

const int NX = 1005 ;
pii dp[2][NX] ;
int cs , adj[NX][NX] , deg[NX] , n , m  ;
bool mem[NX] ;
int vis[2][NX] ;
void ini()
{
    rep( i , n )
    {
        deg[i] = 0 ;
        mem[i] = 0 ;
    }
}

pii DP( int x , int isGard , int par )
{
    if( vis[isGard][x] == cs ) return dp[isGard][x];
    vis[isGard][x]  = cs ;
    mem[x] = 1 ;
    pii tmp , a , b , ans = mp( isGard , 0 );
    rep( i , deg[x] )
    {
        int v = adj[x][i];
        if( v == par ) continue ;
        if( !isGard )
        {
            tmp = DP( v , 1 , x );
            ans.ff += tmp.ff ;
            ans.ss += tmp.ss ;
        }
        else
        {
            a = DP( v , 0 , x );
            b = DP( v , 1 , x );
             if( a.ff < b.ff )
            {
                ans.ff += a.ff ;
                ans.ss += a.ss ;

            }
            else if( b.ff < a.ff )
            {
                ans.ff += b.ff ;
                ans.ss += b.ss ;
                ans.ss++;

            }
            else if( b.ss < a.ss )
            {
                ans.ff += a.ff ;
                ans.ss += a.ss ;
            }
            else
            {
                ans.ff += b.ff ;
                ans.ss += b.ss ;
                ans.ss++;

            }


        }
    }

    return dp[isGard][x] = ans ;
}

int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
  // ms( vis , -1 );
    int t = II ;
    for ( cs = 1 ; cs <= t ; cs++ )
    {
         n = II , m = II ;
         ini();
         rep( i , m )
         {
             int x = II , y = II ;
             adj[x][deg[x]++] = y ;
             adj[y][deg[y]++] = x ;
         }
         pii ans , a , b ;
         ans = mp( 0 , 0 );
         rep( i , n )
         {
              if(mem[i] || deg[i] == 0 )continue ;
              a = DP( i , 0 , -1 );
              b = DP( i , 1 , -1 );

              if( a.ff < b.ff )
            {
                ans.ff += a.ff ;
                ans.ss += a.ss ;

            }
            else if( b.ff < a.ff )
            {
                ans.ff += b.ff ;
                ans.ss += b.ss ;

            }
            else if( b.ss < a.ss )
            {
                ans.ff += a.ff ;
                ans.ss += a.ss ;
            }
            else
            {
                ans.ff += b.ff ;
                ans.ss += b.ss ;

            }

         }
         printf("Case %d: %d %d %d\n",cs,ans.ff , ans.ss , m - ans.ss );
    }
    return 0;
}
