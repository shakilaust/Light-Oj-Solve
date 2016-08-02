
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
int L[NX] , R[NX] , seen[NX] , deg[NX] , adj[NX][NX] , n , Mark[NX][NX] ;// human number then ghost number
char inp[NX][NX];
int vis[NX][NX];
int can[NX][NX];
vector  < pii > graph[NX];

bool ok( int x , int y , int mk )
{
   if( x < 0 || x >= n || y < 0 || y >= n || inp[x][y] == '#' || vis[x][y] == mk ) return 0 ;
   return 1 ;
}
void dfs( int x , int y , int mk , int d )
{
    queue < pii > q ;
    queue < int > dis ;
    q.push(mp(x,y));
    vis[x][y] = mk ;
    dis.push(0);
    while( !q.empty())
    {
        pii now = q.front();
        q.pop();
        int c = dis.front();
        dis.pop();
        if( inp[now.ff][now.ss] == 'G' )
        {
            graph[mk].pb(mp(c,Mark[now.ff][now.ss]));
        }
        rep( i , 4 )
        {
            int nx = now.ff + dx[i];
            int ny = now.ss + dy[i];
            if(ok( nx , ny , mk ) )
            {
                vis[nx][ny] = mk ;
                q.push(mp(nx,ny));
                dis.push(c+1);
            }
        }
    }
}
void ini(int h)
{
    for( int i = 0 ; i <= h ; i++ ) graph[i].clear();
}
bool bmp( int x , int lim )
{
    int sz = graph[x].size();
    rep( i , sz )
    {
        int u = graph[x][i].ss ;
        //cout << graph[x][i].ff << " " << lim << endl ;
        if( graph[x][i].ff > lim || seen[u] ) continue ;
        seen[u] = 1 ;
        if( R[u] == -1 ||  bmp( R[u] , lim ) )
        {
            R[u] = x ;

            return 1;
        }
    }
    return 0 ;
}
bool solve( int dis , int h )
{
    ms( R , -1 );
    for ( int i = 1 ; i <= h ; i++ )
    {
        ms( seen , 0 );
        if( bmp( i , dis ) == 0 ) return 0 ;
    }
    return 1 ;
}
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
    int cs , t = II ;
    for ( cs = 1 ; cs <= t ; cs++ )
    {
        n = II ;
        ms( Mark , 0 );
        ms( vis , 0 );
        int g = 0 , h = 0 ;
        rep( i , n )
        {
            scanf("%s",inp[i]);
            rep( j , n )
            {
                if( inp[i][j] == 'H' ) Mark[i][j] = ++h ;
                if( inp[i][j] == 'G' ) Mark[i][j] = ++g ;
            }
        }
        ini(h);
        rep( i , n )
        {
            rep( j , n )
            {
                if( inp[i][j] == 'H' ) dfs( i , j , Mark[i][j] , 0 );
            }
        }
        int mx = -1 ;
        int low = 0 , high = 100000 ;
        while( low <= high )
        {
            int mid = ( low + high )/2 ;
            if( solve(mid,h))
            {
              //  printf(" mx :: %d\n",mx);
                mx = mid ;
                high = mid - 1;
            }
            else  low = mid + 1 ;
        }

        if( mx == -1 )
        {
            printf("Case %d: Vuter Dol Kupokat\n",cs);
        }
        else
        {

            printf("Case %d: %d\n",cs,2*mx + 2 );
        }
    }

    return 0;
}
