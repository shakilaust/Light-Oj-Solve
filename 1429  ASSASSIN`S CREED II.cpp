
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

#define forab(i, a, b)  for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n)       forab (i, 0, (n) - 1)
#define For(i, n)       forab (i, 1, n)
#define rofba(i, a, b)  for (__typeof (b)i = (b) ; i >= a ; --i)
#define per(i, n)       rofba (i, 0, (n) - 1)
#define rof(i, n)       rofba (i, 1, n)
#define forstl(i, s)    for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)

template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }

//Fast Reader
template<class T>inline bool read(T &x){int c=getchar();int sgn=1;while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}for(x=0;~c&&'0'<=c&&c<='9';c=getchar())x=x*10+c-'0'; x*=sgn; return ~c;}

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

/* **************************************  My code start here ****************************************** */
const int NX = 2005 ;
const int INF = 1 << 29 ;
vector < int > adj[NX] , rev[NX] , G[NX] , can[NX] ;
int n , scc , m ;
int Color[NX] , vis[NX] , match[NX] , dist[NX] , seen[NX] , R[NX] ;
stack < int > stk ;
int q[NX*NX];
void dfs1(int x)
{
    vis[x] = 1 ;
    int sz = adj[x].size();
    rep( i , sz )
    {
        int u = adj[x][i];
        if( vis[u] == 0 ) dfs1( u );
    }
    stk.push(x);
}
void dfs2( int x , int c)
{
    vis[x] = 0 ;
    Color[x] = c ;
    int sz = rev[x].size();
    rep( i , sz )
    {
        int u = rev[x][i];
        if( vis[u] ) dfs2( u , c );
    }
}
bool bpm( int x)
{
    int sz = G[x].size();
    rep( i , sz )
    {
        int u = G[x][i];
        if( seen[u] ) continue ;
        seen[u] = 1 ;
        if( R[u] == -1 || bpm( R[u] ) )
        {
            R[u] = x ;
            return 1 ;
        }
    }
    return 0 ;
}
int bipertite()
{
    ms( R , -1 );
    int ans = 0 ;
    For( i , scc )
    {
        ms( seen , 0 );
        if( bpm( i ) ) ans++;
    }
    return ans ;
}
void ini()
{
    rep ( i , n + 2 )
    {
        adj[i].clear();
        rev[i].clear();
        vis[i] = 0 ;
    }
    while( !stk.empty()) stk.pop();
}
void addEdge( int a , int b )
{
    adj[a].pb(b);
    rev[b].pb(a);
}
void Poss( int x )
{
    vis[x] = 1 ;
    int sz = can[x].size();
    rep( i , sz )
    {
        int u = can[x][i];
        if( vis[u] == 0 ) Poss(u);
    }
}
void constractGraph()
{
    For( i , scc )
    {
        For( j , scc ) vis[j] = 0 ;
        Poss(i);
        For( j , scc )
        {
            if( i != j && vis[j] ) G[i].pb(j+scc);
        }
    }
}
void FreeG()
{
    int lim = scc + scc + 2 ;
    rep ( i , lim ) G[i].clear();
}
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
    int cs , t = II ;
    for ( cs = 1 ; cs <= t ; cs++ )
    {
       n = II , m = II ;
       ini();
       rep( i , m )
       {
           int x = II , y = II ;
           addEdge(x,y);
       }
       For( i , n ) if( vis[i] == 0 ) dfs1(i);
       scc = 0 ;
       while( !stk.empty())
       {
           int u = stk.top();
           stk.pop();
           if( vis[u] == 0 ) continue ;
           dfs2( u , ++scc );
           can[scc].clear();
       }
       For( i , n )
       {
           int sz = adj[i].size();
           rep( j , sz )
           {
               if( Color[i] != Color[adj[i][j]] )
               {
                   can[Color[i]].pb(Color[adj[i][j]]);
               }
           }
       }
       constractGraph();
       int mn = bipertite();
       printf("Case %d: %d\n",cs,scc-mn);

       FreeG();
    }



    return 0;
}
