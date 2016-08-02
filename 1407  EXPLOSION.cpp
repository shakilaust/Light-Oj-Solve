
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
typedef long long ll ;
const int MAXN = 2005;
vector <int> Adj[MAXN] , Rev[MAXN] , order , Ans;
bool vis[MAXN] ;
int comp[MAXN] , Canbe[MAXN] , Inp[10][10] , n , m , k;
int Cal(int x)
{
  if( x < 0 )
  {
      x *= -1 ;
      x--;
      return ((x*2)+1);
  }
  x--;
  return (2*x);
}
void Pre()
{
    int i ;
    for ( i = 0 ; i < MAXN ; i++ )
    {
        vis[i] = 0 ;
        Adj[i].clear();
        Rev[i].clear();
        comp[i] = 0 ;
        Canbe[i] = 0 ;
    }
}
void dfs(int node)
{
    vis[node] = 1 ;
    int i , sz = Adj[node].size();
    for ( i = 0 ; i < sz ; i++ )
    {
        int u = Adj[node][i];
        if( vis[u] ) continue ;
        dfs(u);
    }
    order.pb(node);
}
void scc(int node, int col)
{
    comp[node] = col ;
    int i , sz = Rev[node].size();
    for ( i = 0 ; i < sz ; i++ )
    {
        int u = Rev[node][i];
        if( comp[u] ) continue ;
        scc(u,col);
    }
}

bool two_sat()
{
        order.clear();
        int i ;
        for ( i = 0 ; i < 2*n ; i++ )
        {
            comp[i] = 0 ;
            vis[i] = 0 ;
        }
        for ( i = 0 ; i < 2*n ; i++ ) if(vis[i]==0) dfs(i);
        reverse(order.begin(),order.end());
        int cnt = 1 ;
        for ( i = 0 ; i <2*n ; i++ )
        {
            if(comp[order[i]]==0)
            {
                scc(order[i],cnt);
                cnt++;
            }
        }
        Ans.clear();
        for ( i = 0 ; i < 2*n ; i += 2 )
            { if( comp[i] == comp[i+1] ) return false;
              if( comp[i] > comp[i+1] ) { Ans.pb((i/2)+1); Canbe[(i/2)+1] = 1 ; }

            }
       return 1 ;

}
bool solve(int pos)
{
    if( pos == k ) return two_sat();
    int i ;
    if(Inp[pos][0]==1)
    {
        for( i = 1 ; i < 4 ; i++ )
        {
            int x = Cal(Inp[pos][i]); // !x -> x
            Adj[x^1].pb(x);
            Rev[x].pb(x^1);
            if(two_sat())
            {
                if(solve(pos+1)) return 1 ;
            }
            Adj[x^1].pop_back();
            Rev[x].pop_back();
        }
    }
    else
    {
        for( i = 1 ; i < 4 ; i++ )
        {
            int x = Cal(Inp[pos][i]); // x -> !x
            Adj[x].pb(x^1);
            Rev[x^1].pb(x);
            if(two_sat())
            {
                if(solve(pos+1)) return 1 ;
            }
            Adj[x].pop_back();
            Rev[x^1].pop_back();
        }
    }
    return 0 ;
}
int main()
{
    int cs , t ;
    read(t) ;
    for ( cs = 1 ; cs <= t ; cs++ )
    {
        int i , z , x , y , u , v , j;
        read(n) , read(m) , read(k) ;
        Pre();
        for ( i = 0 ; i < m ; i++ )
        {
            read(z) , read(u) , read(v);
            if ( z == 1 ) // +x +y case
            x = Cal(u) , y = Cal(v) ;
            if( z == 2 ) // (+x || -y ) case
            {
                x = Cal(u) , y = Cal(-v) ;

            }
            if( z == 3 ) // -x -y case
            x = Cal(-u) , y = Cal(-v) ;
            if( z == 4 ) // ( x || y ) && ( -x || -y ) case
            {
                x = u ;
                y = v ;
                u = Cal(u) ;
                v = Cal(v);
                Adj[u^1].pb(v);
                Adj[v^1].pb(u);
                Rev[u].pb(v^1);
                Rev[v].pb(u^1);

                x = Cal(-x);
                y = Cal(-y);

            }
            Adj[x^1].pb(y);
            Adj[y^1].pb(x);
            Rev[y].pb(x^1);
            Rev[x].pb(y^1);
        }


        bool ok  = true ;

       for ( i = 0 ; i < k ; i++ )
       {
           for ( j = 0 ; j < 4 ; j++ ) read(Inp[i][j]);
       }
       printf("Case %d: ",cs);
       if(solve(0))
       {

           printf("Possible");
           cout<<" "<<Ans.size();
           for ( i = 0 ; i < Ans.size() ; i++ )
           {
               cout<<" "<<Ans[i];
           }
           cout<<".\n";
       }
       else
       {
           printf("Impossible.\n");
       }


    }
    return 0;
}
