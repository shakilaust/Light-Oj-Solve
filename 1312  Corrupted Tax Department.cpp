
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

//Fast Reader
template<class T>inline bool read(T &x){int c=getchar();int sgn=1;while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}for(x=0;~c&&'0'<=c&&c<='9';c=getchar())x=x*10+c-'0'; x*=sgn; return ~c;}

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

/* **************************************  My code start here ****************************************** */

const int mod = 10007 ;
const int NX = 10000 + 10 ;

int MaxGrp[ NX ][ 2 ] , ways[ NX ][ 2 ] , n ;
bool vis[ NX ];
vector < int > adj[ NX ] ;

void ini()
{
    rep( i , n + 4 )
    {
        adj[i].clear();
        vis[i] = 0 ;

    }
}
void dfs( int x  )
{
    vis[x] = true ;
    MaxGrp[x][0] = MaxGrp[x][1] = 0 ;
    ways[x][0] = ways[x][1] = 1 ;
    int sz = adj[x].size();
    rep( i , sz )
    {
        int u = adj[x][i];
        if( vis[u] ) continue ;
        dfs( u );
        int mx , tmpmul , svmaxgrp[2] , svways[2];
        mx = max( MaxGrp[u][0] , MaxGrp[u][1] );
        tmpmul = MaxGrp[u][0] > MaxGrp[u][1] ? ways[u][0] : ways[u][1];
        if( MaxGrp[u][0] > 0  && MaxGrp[u][0] == MaxGrp[u][1] ) tmpmul = ways[u][0] + ways[u][1];
        svmaxgrp[0] = MaxGrp[x][0] + mx ;
        svways[0] = ways[x][0] * tmpmul ;
        svmaxgrp[1] = max( MaxGrp[x][1] + mx ,  MaxGrp[x][0] + MaxGrp[u][0] + 1 );
        svways[1] = MaxGrp[x][1] + mx > MaxGrp[x][0] + MaxGrp[u][0] + 1 ? ways[x][1] * tmpmul : ( ways[x][0] * ways[u][0] );
        if( MaxGrp[x][1]  && MaxGrp[x][1] + mx == MaxGrp[x][0] + MaxGrp[u][0] + 1 ) svways[1] = ways[x][1] * tmpmul + ( ways[x][0] * ways[u][0] );
        for( int j = 0 ; j < 2 ; j++ )
        {
            ways[x][j] = svways[j] % mod ;
            MaxGrp[x][j] = svmaxgrp[j];
        }
    }
}
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being

     int cs , t = II ;
     for ( cs = 1 ; cs <= t ; cs++ )
     {
         n = II ;
         ini();
         rep( i , n )
         {
             int u = II ;
             int cnt = II ;
             rep( j , cnt )
             {
                 int v = II ;
                 adj[u].pb(v);
             }
         }
         dfs( 1 );
         int grp = max( MaxGrp[1][0] , MaxGrp[1][1] );
         int way = MaxGrp[1][0] > MaxGrp[1][1] ? ways[1][0] : ways[1][1];
         if( MaxGrp[1][0] > 0 && MaxGrp[1][0] == MaxGrp[1][1] ) way = ways[1][0] + ways[1][1];
         way %= mod ;
         printf("Case %d: %d %d\n",cs,grp,way);
     }

    return 0;
}
