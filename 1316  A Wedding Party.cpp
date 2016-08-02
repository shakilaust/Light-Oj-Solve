
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

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

/* **************************************  My code start here ****************************************** */
const int NX = 505 ;
const int INF = 1 << 29 ;
int deg[NX] , adj[NX][NX] ,cost[NX][NX] ,  n , m , cs , vis[ 17 ][ 1 << 17 ] , shop[ 20 ] ;
int dis[ NX ] , mem[ NX ] , possible[ 18 ][ 18 ] , Isshop[ NX ] , s  , add[ 18 ][ 18 ] ;
pii dp[ 17 ][ 1 << 17 ] ;

void ini()
{
    ms( add , -1 );
    rep( i , n ) deg[i] = Isshop[i] = 0 ;
}
pii DP( int now , int mask )
{

    int &v = vis[now][mask];
    pii &ret = dp[now][mask];
    if( v == cs ) return ret ;
    v = cs ;

    ret = mp( -INF , 0 );
    if( add[now][s+1] != -1 ) ret = mp( 0 , add[now][s+1]);
    pii tmp ;
    //printf("now:: %d\n",now);
    rep( i , s + 1 )
    {
        if( mask & ( 1 << i ) ) continue ;
        if( add[now][i] == -1 ) continue ;
        tmp = DP( i , mask | ( 1 << i ) );
        tmp.ff++;
        tmp.ss += add[now][i];
        if( tmp.ff > ret.ff ) ret = tmp ;
        else if( tmp.ff == ret.ff && tmp.ss < ret.ss ) ret = tmp ;
        //cout << " now " << ret.ff << " " << ret.ss << endl ;

    }

    return ret ;
}
void Dijkstra( int now , int idx )
{
    rep( i , n )
    {
        dis[i] = -1 ;
        mem[i] = 0 ;
    }
    priority_queue < pii > pq ;
    dis[now] = 0 ;
    pq.push(mp(0,now));
    while( !pq.empty())
    {
        pii prv = pq.top();
        pq.pop();
        int pc = (-1)*(prv.ff);
        int x = prv.ss ;
        if( mem[x] ) continue ;
        mem[x] = 1 ;
        rep( i , deg[x])
        {
            int u = adj[x][i];
            int nc = pc + cost[x][i];
            if( mem[u] ) continue ;
            if( dis[u] == -1 || dis[u] > nc )
            {
                dis[u] = nc ;
                pq.push(mp(-nc,u));
            }
        }
    }
    rep( i , s + 1)
    {
        add[idx][i] = dis[shop[i]];

    }
    add[idx][s+1] = dis[n-1];

}
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
  // ms( vis , -1 );
  //  cout << fixed << setprecision(10);

         int t = II ;
         for ( cs = 1  ; cs <= t ; cs++ )
         {
             n = II , m = II , s = II;
             ini();
             int scr = 0 , sink = 0 ;
             For( i , s ) shop[i] = II ;


             rep( i , m )
             {
                 int x  = II , y = II , c = II ;
                 adj[x][deg[x]] = y ;
                 cost[x][deg[x]++] = c ;

             }
             rep( i , s + 1 ) Dijkstra(shop[i],i);
             pii ans = DP(0,1);

             printf("Case %d: ",cs);
             if( ans.ff < 0 ) puts("Impossible");
             else printf("%d %d\n",ans.ff,ans.ss);

         }



    return 0;
}
