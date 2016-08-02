
//BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopner soman boro
 all my suceesses are dedicated to my parents
 The true test of a man's character is what he does when no one is watching.
 Don't let your dreams be dreams.


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

const int NX = 1e5 + 10 ;

vector < int > adj[ NX ] ;

int discover[ NX ] , low[ NX ] , cnt , isQueue[ NX ] , parnt[ NX ] , vis[ NX ] ;
int isbridge[ NX ] , n , m  , d[ NX ];

bool notproceed( int x , int y )
{
    if( isbridge[ x ] && parnt[ x ] == y ) return 1 ;
    if( isbridge[ y ] && parnt[ y ] == x ) return 1 ;
    return 0 ;
}
void ini()
{
    rep( i , n )
    {
        adj[i].clear();
        discover[ i ] = -1 ;
        low[ i ] = -1 ;
        isQueue[ i ] = 0 ;
        vis[ i ] = 0 ;
        d[ i ] = 0 ;
        isbridge[i] = 0 ;
    }
}

void terjan( int node , int par )
{
    low[ node ] = discover[ node ] = cnt++;
    isQueue[ node ] = 1 ;
    int sz = adj[ node ].size();
    rep( i , sz )
    {
        int u = adj[node][i];
       // if( u == par ) continue ;

        if( isQueue[ u ] == 0 )
        {
            parnt[ u ] = node ;
            terjan( u , node );
            low[ node ] = min( low[ node ] , low[ u ] );
            if( low[ u ] > discover[ node ] )
            {
                isbridge[ u ] = 1 ;
            }
        }
        else if( isQueue[ u ] == 1 && parnt[ node ] != u )
        {
            low[ node ] = min( low[ node ] , discover[ u ] );
        }
    }
    isQueue[ node ] = 2 ;
}

bool cyclefound ;

void dfs( int x , int parnt , int cst )
{
    cnt++ ;
    d[ x ] = cst ;
    int sz = adj[ x ].size();
    vis[ x ] = 1 ;
    rep(  i , sz )
    {
        int u = adj[ x ][ i ];
        if( notproceed( x , u ) ) continue ;
        if( vis[ u ] == 0 ) dfs( u , x , cst + 1 );
        else if( vis[ u ] == 1  && ( d[ u ] - d[ x ] ) % 2 == 0 ) cyclefound = 1 ;

    }
}
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being

    int cs , t = II ;
    for ( cs = 1 ; cs <= t ; cs++ )
    {
        cnt = 0 ;
        n = II , m = II ;
        ini();
        rep( i , m )
        {
            int x = II , y = II ;
            adj[x].pb( y );
            adj[y].pb( x );
        }
        int ans = 0 ;
        rep( i , n )
        {
            if( isQueue[ i ] == 0  ) terjan( i , -1 );
        }
        rep( i , n )
        {
            d[i] = 0 ;
            vis[ i ] = 0 ;
        }
        rep( i , n )
        {
            if( vis[i]  ) continue ;
            cnt = 0 ;
            cyclefound = 0 ;
            dfs( i , -1 , 1  );
            if( cyclefound ) ans += cnt ;
        }
        printf("Case %d: %d\n",cs,ans);

    }


    return 0;
}

/*
4

4 4
1 2
1 3
1 0
3 2

9 7
3 5
4 3
3 7
4 5
6 5
1 0
7 2

9 15
7 2
3 5
1 2
3 7
1 8
1 6
4 3
7 6
4 0
4 7
7 5
5 2
5 6
2 6
2 4

10 9
4 3
8 3
5 7
4 6
6 3
8 1
4 5
7 3
6 2

*/
