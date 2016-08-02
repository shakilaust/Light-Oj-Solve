
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
const int MX = 1005 ;
vector < pii > adj[MX] ;
int dfs(int x, int par)
{
    int sz = adj[x].size() , i;
   // printf("x :: %d sz :: %d\n",x,sz);
    int nim = 0 ;
    for ( i = 0 ; i < sz ; i++ )
    {

        int v = adj[x][i].ff;
        int w = adj[x][i].ss ;
        if( v == par ) continue;
        int r = dfs(v,x);
        // printf("x :: %d v :: %d w:: %d\n",x,v,w);
        if( w == 1 ) nim ^= ( r + 1 );
        else nim ^= r ^ ( w & 1);
    }
    return nim ;
}
int main()
{
    // ios_base::sync_with_stdio(0); cin.tie(0);
    int cs , t ;
    read(t);
    for ( cs = 1 ; cs <= t ; cs++ )
    {
        int n , i ;
        read(n);
        rep(i,n-1)
        {
            int x , y , z ;
            read(x) , read(y) , read(z);
            adj[x].pb(mp(y,z));
            adj[y].pb(mp(x,z));
        }
        if( dfs(0,-1))
        {
            printf("Case %d: Emily\n",cs);
        }
        else
        {
            printf("Case %d: Jolly\n",cs);
        }
        if( cs != t )
        {
            rep(i,n) adj[i].clear();
        }
    }
    return 0;
}
