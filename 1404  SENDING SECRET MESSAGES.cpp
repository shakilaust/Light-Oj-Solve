
/*
   Team ::  AUST_toothless
*/

#include <bits/stdc++.h>

#define pb push_back
#define all(x) x.begin(),x.end()
#define ms(a,v) memset(a,v,sizeof a)
#define II ( { int a ; read(a) ; a; } )
#define LL ( { Long a ; read(a) ; a; } )
#define DD ({double a; scanf("%lf", &a); a;})
#define ff first
#define ss second
#define mp make_pair

#define pi 3.1415926535897932384626433832795
using namespace std;

typedef long long Long;
typedef long long int64;
typedef unsigned long long ull;

typedef pair<int,int>pii;
typedef pair<string,int>psi;
typedef pair<Long,Long>pll;
typedef pair<double,double>pdd;

typedef vector<int>    vi;
typedef vector<Long>   vl;
typedef vector<string> vs;
typedef vector<pii>  vpii;
typedef set<int> si;

#define forab(i, a, b)	for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n)		forab (i, 0, (n) - 1)
#define For(i, n)		forab (i, 1, n)
#define rofba(i, a, b)	for (__typeof (b)i = (b) ; i >= a ; --i)
#define per(i, n)		rofba (i, 0, (n) - 1)
#define rof(i, n)		rofba (i, 1, n)
#define forstl(i, s)	for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)


#define __( args... ) { dbg , args ; cerr << endl; }

struct debugger {
    template< typename T > debugger & operator , ( const T &v ) {
        cerr << v << "\t" ;
        return *this;
    }
}dbg;
// Pair Print
template< class A , class B > ostream &operator << ( ostream &o, const pair<A,B> &p ) {
    return o<<"(" << p.ff << ", " << p.ss << ")" ;
}
//Vector Print
template<class T> ostream& operator<<(ostream& o, const vector<T>& v) {
    o << "[";
    forstl(it,v) o << *it << ", " ;
    return o << "]";
}
//Set Print
template<class T> ostream& operator<<(ostream& o, const set<T>& v) {
    o << "[";
    forstl(it,v) o << *it << ", " ;
    return o << "]";
}
template<class T> inline void MAX( T &a , T b) { if (a < b ) a = b; }
template<class T> inline void MIN( T &a , T b) { if (a > b ) a = b; }

//Fast Reader
template< class T > inline bool read( T &x ) {
    int c = getchar() ;
    int sgn = 1;
    while( ~c && c < '0' || c > '9' ) {
        if( c == '-' )sgn = -1 ;
        c = getchar() ;
    }
    for( x = 0 ; ~c && '0' <= c && c <= '9' ; c = getchar() ) x = x * 10 + c - '0' ;
    x *= sgn ;
    return ~c ;
}

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

Long BigMod( Long  b , Long  p ,Long  m ) {
    Long r = 1 ;
    while( p ) {
        if( p & 1 ) r = ( r * b ) % m ;
        p >>= ( 1LL ) , b = ( b * b ) % m ;
    }
    return r ;
}
Long toInt(string s) {
    Long r = 0 ;
    istringstream sin(s);
    sin >> r ;
    return r ;
}
string toString(Long x) {
    stringstream s;
    s << x ;
    return s.str();
}
vs Split( string s ) {
    vs a ;
    istringstream ss(s) ;
    string b ;
    while(ss >> b ) a.pb( b ) ;
    return a;
}
string i2b( Long a ) {
    string s ;
    do { s += ( a & 1 ) + '0' ,  a >>= 1; } while( a );
    reverse(all(s));
    return s;
}

#define EPS 1e-10

typedef long long ll ;
const int MX = 505 ;
const ll INF = 1e16 ;
struct NODE
{
    ll v , Cap , Cost , RevInd ;
};
vector < NODE > edge[MX+7];
ll par[MX] , pid[MX];
ll nV , nE , scr , sink , p; // here source will ne always 0 and sink will be nV+1
ll dis[MX+7];
void ini()
{
    rep(i,nV+2) edge[i].clear();
}
void setEdge(ll u , ll v , ll cap , ll cost)
{
    NODE U = {v,cap,cost,edge[v].size()};
    NODE V = {u,0,-cost,edge[u].size()};
    edge[u].pb(U);
    edge[v].pb(V);
}
void input()
{
          read(nV) , read(nE) , read(p);
          ini();
          scr = 0 ;
          sink = nV+1 ;
          setEdge(0,1,INF,0);
          setEdge(nV,sink,p,0);
          setEdge(sink,nV,p,0);
          ll u , v , cos , cap ;
         rep(i,nE)
         {
             read(u) , read(v) , read(cap) , read(cos);
             setEdge(u,v,cap,cos);
             setEdge(v,u,cap,cos);
            // setEdge(u,v,1,cos+extra);
         }
}
bool BFORD()
{
    ll i , u , tmp ;
    for ( i = 0 ; i <= sink ; i++ )
    {
        dis[i] = INF ;
        par[i] = -1 ;
    }
    dis[scr] = 0 ;
    bool Ischange = true ;
    while(Ischange)
    {
        Ischange = false ;
        for ( u = scr ; u <= sink ; u++ )
        {
            int sz = edge[u].size();
            for ( i = 0 ; i < sz ; i++ )
            {
                if(!edge[u][i].Cap) continue;
                ll v = edge[u][i].v ;
                tmp = dis[u] + edge[u][i].Cost ;
                if( dis[v] > tmp )
                {
                    dis[v] = tmp ;
                    par[v] = u ;
                    pid[v] = i ; // koto number edge ;
                    Ischange = 1 ;
                }
            }
        }
    }
    return par[sink] != -1 ;
}
ll findflow( ll s , ll t )
{
    ll Cap = edge[par[t]][pid[t]].Cap ;
    if( s == par[t] ) return Cap ;
    return min( Cap , findflow(s,par[t]));
}
ll AgumentPath(ll s , ll t , ll v )
{
    if( s == t ) return 0 ;
    ll Cost = edge[par[t]][pid[t]].Cost*v ;
    edge[par[t]][pid[t]].Cap -= v ;
    edge[t][edge[par[t]][pid[t]].RevInd].Cap += v ;
    return Cost + AgumentPath(s,par[t],v);
}
void MinCost( ll &Flow , ll &Cost)
{
    Flow = 0 , Cost = 0 ;
    while(BFORD())
    {
        ll v = findflow(scr,sink);
        Flow += v ;
        Cost += AgumentPath(scr,sink,v);
    }
}
int main() {
#ifdef LOCAL
    freopen ( "input.txt" , "r", stdin) ;
  //freopen ( "output.txt" , "w" , stdout );
#endif
    int cs , t ;
    read(t);
   For( cs , t )
   {
       input();
       ll flow , cost ;
       MinCost(flow,cost);
    //   printf("flow :: %lld cost :: %lld\n",flow,cost);
       if( flow < p ) printf("Case %d: impossible\n",cs);
       else printf("Case %d: %lld\n",cs,cost);
   }
}
