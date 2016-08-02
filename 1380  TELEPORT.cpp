

 //BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopner soman boro
 Author :: Shakil Ahmed
.............AUST_CSE27.........
 prob   ::
 Type   ::
 verdict::
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>
#include <set>
#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <list>
#include <map>
#include <queue>
#include <sstream>
#include <utility>
#define pb push_back
#define mp make_pair
#define pi acos(-1.0)
#define ff first
#define LL long long
#define ss second
#define rep(i,n) for(i = 0; i < n; i++)
#define REP(i,n) for(i=n;i>=0;i--)
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define ROF(i,a,b) for(int i = a; i >= b; i--)
#define re return
#define QI queue<int>
#define SI stack<int>
#define pii pair <int,int>
#define MAX
#define MOD
#define INF 1<<30
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define memo(a,b) memset((a),(b),sizeof(a))
#define G() getchar()
#define MAX3(a,b,c) max(a,max(b,c))

double const EPS=3e-8;
using namespace std;


template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template <class T> inline T bigmod(T p,T e,T M)
{
    if(e==0)return 1;
    if(e%2==0){LL t=bigmod(p,e/2,M);return (T)((t*t)%M);}
    return (T)((LL)bigmod(p,e-1,M)*(LL)p)%M;
}

template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}
//Fast Reader
template<class T>inline bool read(T &x){int c=getchar();int sgn=1;while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}for(x=0;~c&&'0'<=c&&c<='9';c=getchar())x=x*10+c-'0'; x*=sgn; return ~c;}

/* **************************************  My code start here ****************************************** */
const int Maxn = 1005 ; // Highest Vertex
struct edge
{
    int u , v , w ;
    edge() {}
    edge(int _u, int _v , int _w ) { u = _u , v = _v , w = _w ; }
};
int nV , nE , root ; // nV = number of vertex , nE = number of edge , root is root
int vis[Maxn] , parnt[Maxn] ; // vis[] will store from which cycle it belogs , pre[] store its parnt
int Idx[Maxn] ; // will store new indxing Id
int dis[Maxn] ; // store the lowest incoming edge of a root
vector < edge > adj ;
void DMST()
{
    int Res  = 0 , i , u ,  v , w  ;
    while(1)
    {
        int i  ;
        rep(i,nV)
        {
            dis[i] = INF ;
            vis[i] = -1 ;
            Idx[i] = -1 ;
        }
        rep(i,nE)
        {
            u = adj[i].u ;
            v = adj[i].v ;
            w = adj[i].w ;
            if ( u != v && dis[v] > w) // lowest Incoming Edge
            {
                parnt[v] = u ;
                dis [v] = w ;
            }
        }
        parnt[root] = root ;
        dis[root] = 0 ;
        rep(i,nV)
        {
            if ( dis[i] == INF )
            {
                puts("impossible"); // its not possible to reach
                return ;
            }
            Res += dis[i];
        }
        int idx = 0 ;
        // cycle detection
        rep(i,nV)
        {

            if(vis[i]==-1) // not yet visited
            {
                int cur = i ;
                while ( vis[cur]==-1)
                {
                    vis[cur] = i ;
                    cur = parnt[cur] ;
                }
                if ( cur == root || vis[cur] != i )  continue ; // not cycle
                Idx[cur] = idx ; // new indexing
                for (  u = parnt[cur] ; cur != u ; u = parnt[u] )
                Idx[u] = idx ;
                idx++;
            }
        }
        if(idx==0) break ; // no cycle
        for ( i = 0 ; i < nV ; i++ )
        {
            if(Idx[i]==-1) // yet not find any grp
            {
                Idx[i] = idx++;
            }
        }
        rep(i,nE)
        {
            adj[i].w -= dis[adj[i].v];
            adj[i].u = Idx[adj[i].u] ;
            adj[i].v = Idx[adj[i].v];
        }
        nV = idx++;
        root = Idx[root];
    }
    printf("%d\n",Res);
}
int main()
{
    int cs , t  ;
    read(t);
    for ( cs = 1 ; cs <= t ; cs++ )
    {
        read(nV) , read(nE) , read(root) ;
        int i , u , v , w ;
        adj.clear();
        rep(i,nE)
        {
            read(u) , read(v) , read(w) ;
            adj.pb(edge(u,v,w));
        }
        printf("Case %d: ",cs);
        DMST();
    }
   return 0;
}
