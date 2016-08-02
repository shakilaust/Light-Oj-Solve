
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
#define memo(a,b) memset((a),(b),sizeof(a))
#define G() getchar()
#define MAX3(a,b,c) max(a,max(b,c))

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
const int MX = 105 ;
int deg[MX] , adj[MX][MX] , prev[MX] , cap[MX][MX] , q[MX*MX*MX] , n , m;
int dinic(int scr , int sink)
{
    int flow = 0 ;
    while( 1 )
    {

        memo(prev,-1);
        int qpush = 0 , qpop = 0 , x , u , v;
        prev[q[qpush++] = scr ] = -2 ;
        while( qpush > qpop && prev[sink] == -1 )
        {
            int  x = q[qpop++];
            for (   int z = 0 ; z < deg[x] ; z++ )
            {
                int y = adj[x][z] ;
                if( prev[y] == -1 && cap[x][y] > 0 )
                {
                    prev[y] = x ;
                    q[qpush++] = y ;
                }
            }
        }
        if( prev[sink] == -1 ) break ;
        for ( int z = 0 ; z < deg[sink] ; z++ )
        {
            if ( prev[ u = adj[sink][z] ] != -1  && cap[u][sink] > 0 )
            {
                int add = cap[u][sink];
                for ( v = prev[u] ,x = u ; v >= 0  ;  v = prev[v] )
                {

                    add = min(add , cap[v][x] );
                    x = v ;
                }
                if( add == 0 ) continue ;
                cap[x][sink] -= add;
                cap[sink][x] += add;
                 for ( v = prev[u] ,x = u ; v >= 0  ;  v = prev[v] )
                {

                    cap[v][x] -= add;
                    cap[x][v] += add;
                     x = v ;
                }
                flow += add;

            }
        }
    }
    return flow;
}
void input()
{
    read(n) , read(m);

    int i , x , y , z ;
    memo(deg,0);
    memo(cap,0);

     cap[1][1+n] = ( 1 << 29);
     cap[n][n+n] = ( 1 << 29);
     adj[1][deg[1]++] = 1+n ;
     adj[1+n][deg[1+n]++] = 1 ;
     adj[n][deg[n]++] = n+n ;
     adj[n+n][deg[n+n]++] = n ;
    for ( i = 0 , x = 2 ; i < n-2 ; i++ , x++ )
    {
        read(y);
        cap[x][x+n] += y ;
        adj[x][deg[x]++] = x+n ;
        adj[x+n][deg[x+n]++] = x ;
    }

    for ( i = 0 ; i < m ; i++ )
    {
        read(x) , read(y) , read(z);
        cap[x+n][y] += z ;
        cap[y+n][x] += z ;
        adj[x+n][deg[x+n]++] = y ;
        adj[y][deg[y]++] = x+n;
        adj[y+n][deg[y+n]++] = x ;
        adj[x][deg[x]++] = y+n ;

    }

}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int cs , t ;
    read(t);
    for( cs = 1 ; cs <= t ; cs++ )
    {
        input();
        printf("Case %d: %d\n",cs,dinic(1,n+n));
    }
    return 0;
}
