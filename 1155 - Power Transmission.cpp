//BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopner soman boro
 all my suceesses are dedicated to my parents
 The true test of a man's character is what he does when no one is watching.


 Author :: Shakil Ahmed
.............AUST_CSE27.........
 prob   ::
 Type   ::
 verdict::
 */

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair

// Macro
#define eps 1e-9
#define pi acos(-1.0)
#define ff first
#define ss second
#define re return
#define QI queue<int>
#define SI stack<int>
#define SZ(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sq(a) ((a)*(a))
#define distance(a,b) (sq(a.x-b.x) + sq(a.y-b.y))
#define iseq(a,b) (fabs(a-b)<eps)
#define eq(a,b) iseq(a,b)
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


const int NX = 205 ;
const int MX = 1e6 + 10 ;
Long cap[ NX ][ NX ] , limit[ NX ] ;

int adj[ NX ][ NX ] , deg[ NX ] , n , s , t , d , b , m ;
int startnode[ NX ] , endnode[ NX ] ;
int que[ MX + 10 ];
int prv[ NX ];

void ini()
{
    rep( i , t + 2 )
    {
        rep( j , t + 2 )
        {
            cap[i][j] = 0 ;
        }
        deg[i] = 0 ;
    }
}

Long Maxflow()
{
    int u , v , w , i , j , k ;
    Long flow = 0 , add = 0 ;
    while( 1 )
    {
        ms( prv , -1 );
        int qpush = 0 , qpop = 0 ;
        que[ qpush++ ] = s ;
        prv[ s ] = -2 ;
        while( qpush != qpop && prv[t] == -1 )
        {
            u = que[ qpop++ ];
            rep( i , deg[u] )
            {
                v = adj[u][i];
                if( prv[v] == -1 && cap[u][v] )
                {
                    que[ qpush++ ] = v ;
                    prv[ v ] = u ;
                }
            }
        }
        if( prv[t] == -1 ) break ;
        rep( i , d )
        {
            j = endnode[i] ;
            if( prv[j] == -1 || cap[j][t] == 0 )  continue ;
            add = cap[j][t];
            for ( v = j , u = prv[j] ; u >= 0 ; )
            {
                add = min( add , cap[u][v] );
                v = u ;
                u = prv[u];
            }
            if( !add ) continue ;
            cap[j][t] -= add ;
            cap[t][j] += add ;
            for ( v = j , u = prv[j] ; u >= 0 ; )
            {
                cap[u][v] -= add ;
                cap[v][u] += add ;
                v = u ;
                u = prv[u];
            }
            flow += add ;
        }
    }
    return flow ;
}
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being

    int cs , r = II ;
    for ( cs = 1 ; cs <= r ; cs++ )
    {
        n = II ;
        s = 0 , t = n + n + 1 ;
        ini();
        rep( i , n )
        {
            limit[ i + 1 ] = LL ;
        }
        m = II ;
        rep ( i , m )
        {
            int u = II , v = II ;
            Long c = LL ;
            cap[ u + n ][ v ] = c ;
            cap[ v ][ u + n ] = 0 ;
            adj[ u + n ][ deg[ u + n ]++ ] = v ;
            adj[ v ][ deg[ v ]++ ] = u + n ;
        }
        b = II , d = II ;
        rep ( i , b )
        {
            startnode[i] = II ;
            cap[ 0 ][ startnode[i] ] = ( 1 << 29 );
            cap[ startnode[i] ][ 0 ] = 0 ;
            adj[ 0 ][ deg[0]++ ] = startnode[ i ];
            adj[ startnode[i] ][ deg[ startnode[i] ]++ ] = 0 ;
        }
        rep( i , d )
        {
            endnode[i] = II ;
            endnode[i] += n ;
            cap[ endnode[i] ][ t ] = ( 1 << 29 ) ;
            cap[ t ][ endnode[i] ] = 0 ;
            adj[ endnode[i] ][ deg[ endnode[i] ]++ ] = t ;
            adj[ t ][ deg[t]++ ] = endnode[i] ;
        }
        for ( int i = 1 ; i <= n ; i++ )
        {
            int frm = i , to = i + n ;
            cap[ i ][ i + n ] = limit[ i ] ;
            cap[ i + n ][ i ] = 0 ;
            adj[ i ][ deg[i]++ ] = i + n ;
            adj[ i + n ][ deg[ i + n ]++ ] = i ;
        }
        printf("Case %d: %lld\n",cs,Maxflow());

    }


    return 0;
}
