
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
const int maxn = 40000+10;
const int NIL = 0;
vector < pii > inp ;
vector <int> g[maxn];
int match[maxn] ,dist[maxn] , inf_size, sz , n , m , k , idx;
map <pii,int> Graph;
bool vis[210][210];
int dx[] = { 1, 1, 2, 2, -1, -1, -2 ,-2};
int dy[] = { 2, -2, 1, -1, 2, -2, 1, -1};
bool ok(int x , int y)
{
    if( x < 0 || y < 0 || x >= n || y >=m  ) return 0;
    return 1;
}

bool bfs()
{
    int x , y , i;
    queue <int > q ;
    for ( i = 1 ; i <= idx ; i++ )
    {
        if(match[i] == NIL )
        {
            dist[i] = 0 ;
            q.push(i);
        }
        else dist[i] = INF ;
    }
    dist[NIL] = INF;
    while(!q.empty())
    {
        x = q.front();
        q.pop();
        if(x!=NIL) {
        rep(i,g[x].size())
        {
            y = g[x][i];
            if(dist[match[y]]==INF)
            {
                dist[match[y]] = dist[x] + 1 ;
                q.push(match[y]);
            }
        }
        }
    }
    return dist[NIL] != INF ;
}
bool dfs(int x)
{

    if(x != NIL ) {
    int i ;
    rep(i,g[x].size())
    {
        int y = g[x][i];

        if(dist[match[y]] == dist[x]+1 && dfs(match[y]))
        {
            match[x] = y ;
            match[y] = x ;
            return 1;
        }
    }
    dist[x] = INF;
    return 0;
    }
    return 1;
}
int Hopcropt()
{
    int matching = 0  , i;
    memo(match,0);

    while(bfs())
    {
        for ( i = 1 ; i <=idx; i++ )
        {
            if(match[i] == 0 && dfs(i) )
            {
                matching++;
            }
        }
    }
    //printf("matching:: %d\n",matching);
    return matching;
}
int main()
{
  // freopen("input.txt","r",stdin);
     //freopen("output.txt","w",stdout);
     int cs , t , i , x , y , j;
     read(t);
     for ( cs = 1 ; cs <= t ; cs++ )
     {
         read(n) , read(m) , read(k) ;
         Graph.clear();
         rep(x,n+1) rep(y,m+1) vis[x][y] = 0 ;
         rep(i,k)
         {
             read(x) , read(y) ;
             vis[x-1][y-1] = 1 ;
         }
         rep(i,(n*m+2)) g[i].clear();
         idx = 0 ;
         for ( i = 0 ; i < n ; i++ )
         {
             for ( j = 0 ; j < m ; j++ )
             {
                 if(Graph[mp(i,j)]==0 && vis[i][j]==0) Graph[mp(i,j)] = ++idx;
             }
         }
         for ( i = 0 ; i < n ; i++)
         {
             for ( j = 0 ; j < m ; j++ )
             {
                  x = i ;
                  y = j ;

                  for ( int t = 0 ; t < 8 ; t++)
                  {
                      int nx = x + dx[t];
                      int ny = y + dy[t];
                      if(!ok(nx,ny) || vis[nx][ny]) continue;

                      g[Graph[mp(x,y)]].pb(Graph[mp(nx,ny)]);
                  }
             }
         }
         printf("Case %d: %d\n",cs,(m*n)-k-Hopcropt());

     }
   return 0;
}
