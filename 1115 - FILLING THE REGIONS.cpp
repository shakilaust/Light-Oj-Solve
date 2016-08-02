
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

int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

/* **************************************  My code start here ****************************************** */
const int NX = 55 ;
char inp[NX][NX];
bool vis[NX][NX] , taken[NX] ;
int n , m ;
bool ok( int x , int y , char match )
{
    if( x < 0 || x >= n || y < 0 || y >= m || vis[x][y] || match == inp[x][y] ) return 0 ;
    return 1 ;
}
void bfs(char match)
{
    ms( vis , 0 );
    queue < pii > q ;
    int i , j ;
    for ( i = 0 ; i < n ; i++ )
    {
        if( inp[i][0] != match )
        {
            vis[i][0] = 1 ;
            q.push(mp(i,0));
        }
        if( inp[i][m-1] != match )
        {
            vis[i][m-1] = 1 ;
            q.push(mp(i,m-1));
        }
    }
    for( i = 0 ; i < m ; i++ )
    {
        if( inp[0][i] != match )
        {
            vis[0][i] = 1 ;
            q.push(mp(0,i));
        }
        if( inp[n-1][i] != match )
        {
            vis[n-1][i] = 1 ;
            q.push(mp(n-1,i));
        }
    }
    while( !q.empty())
    {
        pii p = q.front();
        q.pop();
        rep( i , 4 )
        {
            int nx = p.ff + dx[i];
            int ny = p.ss + dy[i];
            if( ok(nx,ny,match ) )
            {
                vis[nx][ny] = 1 ;
                q.push(mp(nx,ny));
            }

        }
    }
    rep( i , n ) rep( j , m ) if( !vis[i][j] ) inp[i][j] = match ;
}
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
    int cs , t = II ;
    for ( cs = 1 ; cs <= t ; cs++ )
    {
        n = II , m = II ;
        rep( i , n ) scanf("%s",inp[i]);
        ms( taken ,  0 );
        rep( i , n )
        {
            rep( j , m )
            {
                if( inp[i][j] != '.' && taken[inp[i][j]-'A'] == 0 )
                {
                    taken[inp[i][j] - 'A'] = 1 ;
                    bfs(inp[i][j]);
                }
            }
        }
        printf("Case %d:\n",cs);
        rep(i,n) printf("%s\n",inp[i]);
    }


    return 0;
}
