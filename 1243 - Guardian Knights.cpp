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
#define __(args...) {dbg,args; cerr<<endl;}
struct debugger{template<typename T> debugger& operator , (const T& v){cerr<<v<<"\t"; return *this; }}dbg;
#define __1D(a,n) rep(i,n) { if(i) printf(" ") ; cout << a[i] ; }
#define __2D(a,r,c,f) forab(i,f,r-!f){forab(j,f,c-!f){if(j!=f)printf(" ");cout<<a[i][j];}cout<<endl;}

template<class A, class B> ostream &operator<<(ostream& o, const pair<A,B>& p){ return o<<"("<<p.ff<<", "<<p.ss<<")";} //Pair print
template<class T> ostream& operator<<(ostream& o, const vector<T>& v){ o<<"[";forstl(it,v)o<<*it<<", ";return o<<"]";} //Vector print
template<class T> ostream& operator<<(ostream& o, const set<T>& v){ o<<"[";forstl(it,v)o<<*it<<", ";return o<<"]";} //Set print

//Fast Reader
template<class T>inline bool read(T &x){int c=getchar();int sgn=1;while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}for(x=0;~c&&'0'<=c&&c<='9';c=getchar())x=x*10+c-'0'; x*=sgn; return ~c;}

int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

/* **************************************  My code start here ****************************************** */

const int NX = 500;
const int INF = 1e9;
struct NODE
{
    int to , cap , cost , revId ;
};

int Qx[ NX * NX ] , Qy[ NX * NX ];


int par[ NX ] , pid[ NX ] , dis[ NX ][ NX ] , d[ NX ];
int CapKnight[ NX ];
bool vis[ NX ][ NX ];
vector < NODE > edge[ NX + 7 ];

int source , sink , n , k , m ;

char inp[ NX ][ NX ];
int IdforMall[ NX ][ NX ];

pair < int , int > Mall[ NX ];


void AddEdge( int u , int v , int cap , int cost )
{
    NODE U = { v , cap , cost , edge[v].size()};
    NODE V = { u , 0 , -cost , edge[u].size()};
    edge[u].pb(U);
    edge[v].pb(V);

}
bool ok( int x , int y )
{
    if( x < 0 || x >= n || y < 0 || y >= n || inp[x][y] == '#' || vis[x][y] ) return 0 ;
    return 1 ;
}
void ini()
{
    for( int i = 0 ; i < NX ; i++ )
    {
        edge[i].clear();
    }
}

void input()
{

    for( int i = 0 ; i < n ; i++ )
    {
        scanf("%s",inp[i]);
    }
    for( int i = 1 ; i <= k ; i++ )
    {
        CapKnight[i] = II ;
    }
    int startMallId = k + 1 ;
    for( int i = 0 ; i < n ; i++ )
    {
        for( int j = 0 ; j < n ; j++ )
        {
            if( inp[i][j] == 'm' )
            {
                IdforMall[i][j] = startMallId;
                Mall[startMallId] = mp( i , j );
                startMallId++;
            }
        }
    }
}

void bfs( int x , int y )
{
    for( int i = 0 ; i < n ; i++ )
    {
        for( int j = 0 ; j < n ; j++ )
        {
            vis[ i ][ j ] = 0 ;
        }
    }
    vis[ x ][ y ] = 1 ;
    dis[ x ][ y ] = 0 ;
    int fnt = 0 , bck = 0 ;
    Qx[ fnt ] = x ;
    Qy[ fnt++ ] = y ;
    while( fnt != bck )
    {
        int px = Qx[bck];
        int py = Qy[bck++];
        for( int i = 0 ; i < 4 ; i++ )
        {
            int nx = px + dx[i];
            int ny = py + dy[i];
            if( ok(nx,ny) )
            {
                vis[nx][ny] = 1 ;
                Qx[fnt] = nx ;
                Qy[fnt++] = ny;
                dis[nx][ny] = dis[px][py] + 1 ;

            }
        }
    }

}

bool isKnight( int x , int y )
{
    if( inp[x][y] >= 'A' && inp[x][y] <= 'Z' ) return 1 ;
    else return 0;

}

void makeGraph()
{
    for( int i = 0 ; i < n ; i++ )
    {
        for( int j = 0 ; j < n ; j++ )
        {
            if( isKnight(i,j))
            {
                bfs(i,j);
                int knightNumber = inp[i][j] - 'A' + 1 ;
                for( int ii = k + 1 ; ii <= k + m ; ii++ )
                {
                    int mx = Mall[ii].ff;
                    int my = Mall[ii].ss;
                    if( vis[mx][my] == 1 ) // possible to go
                    {
                        int dd = dis[mx][my];
                        AddEdge(knightNumber, ii, 1, dd);

                    }
                }
            }
        }
    }
    for( int i = 1 ; i <= k ; i++ )
    {
        AddEdge( source , i , CapKnight[ i ] , 0 );
    }
    for( int i = k + 1 ; i <= k + m ; i++ )
    {
        AddEdge( i , sink , 1 , 0 );
    }
}

bool BFORD()
{
    for( int i = 0 ; i <= sink ; i++ )
    {
        par[i] = -1 ;
        d[i] = INF ;
    }
    d[source] = 0 ;
    bool isChanged = true ;
    while( isChanged )
    {
        isChanged = false;
        for( int i = 0 ; i <= sink ; i++ )
        {
            int sz = edge[i].size();
            for( int j = 0 ; j < sz ; j++ )
            {
                if(!edge[i][j].cap) continue;
                int u = edge[i][j].to;
                int tmpd = d[i] + edge[i][j].cost;
                if( d[u] > tmpd )
                {
                    d[u] = tmpd;
                    par[u] = i;
                    pid[u] = j;
                    isChanged = 1 ;

                }
            }
        }
    }
    return par[sink] != -1;
}

int AgumentPath( int s , int t )
{
    if( s == t ) return 0 ;
    int cst = edge[par[t]][pid[t]].cost;
    edge[par[t]][pid[t]].cap -= 1 ;
    edge[t][edge[par[t]][pid[t]].revId].cap += 1 ;
    return cst + AgumentPath( s , par[t] );
}
int MinCostMaxFlow()
{
    int Cost = 0 ;
    while( BFORD())
    {
        Cost += AgumentPath( source , sink );
    }
    return Cost;
}
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being


    int cs , t = II ;
    for( cs = 1 ; cs <= t ; cs++ )
    {
        n = II , k = II , m = II ;
        source = 0 , sink = k + m + 1 ;
        ini();
        input();
        makeGraph();
        printf("Case %d: %d\n",cs,MinCostMaxFlow());
    }



    return 0;
}
