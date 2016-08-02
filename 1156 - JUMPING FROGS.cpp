
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
const int MX = 225 ;
const int INF = (1 << 20);
struct abc
{
    char flag ;
    int value;
}inp[MX];
int deg[MX] , adj[MX][MX] , prev[MX] , cap[MX][MX] , q[MX*MX] , n , d;
int dinic(int scr , int sink )
{
    int flow = 0 ;
    while( 1 )
    {


        int qpush = 0 , qpop = 0 , x , u , v;
        memo(prev,-1);
        prev[q[qpush++] = scr ] = -2 ;
        while( qpush > qpop && prev[sink] == -1 )
        {
            int  x = q[qpop++];
            for (   int z = 0 ; z < deg[x] ; z++ )
            {
                int y = adj[x][z] ;
                if( prev[y] == -1 && cap[x][y] > 0 )
                {
                    prev[y] = x ;
                    q[qpush++] = y ;
                }
            }
        }
        if( prev[sink] == -1 ) break ;
        for ( int z = 0 ; z < deg[sink] ; z++ )
        {
            if ( prev[ u = adj[sink][z] ] != -1  && cap[u][sink] > 0 )
            {

                int add = cap[u][sink];

                for ( v = prev[u] ,x = u ; v >= 0  ;  v = prev[v] )
                {

                    add = min(add , cap[v][x] );
                    x = v ;
                }
                if( add == 0 ) continue ;
                cap[u][sink] -= add;
                cap[sink][u] += add;
                 for ( v = prev[u] ,x = u ; v >= 0  ;  v = prev[v] )
                {

                    cap[v][x] -= add;
                    cap[x][v] += add;
                     x = v ;
                }
                flow += add;

            }
        }
    }
    return flow;
}
void input()
{
          scanf("%d %d",&n,&d);
          char str[110];
          int i ;
          for ( i = 1 ; i <= n ; i++ )
          {
              scanf("%s",str);
              sscanf(str,"%c-%d",&inp[i].flag,&inp[i].value);
          }
}
void build(int limit)
{
    memo(deg,0);
    memo(cap,0);
    int scr = 0 , sink = n+n+1 ;
    int i , j ;
    for ( i = 1 ; i <= n ; i++ )
    {
        if( inp[i].flag == 'B' )
        {
            cap[i][i+n] = 2 ; // 2ibar jaowa asa kora jabe
            adj[i][deg[i]++] = i+n;
            adj[i+n][deg[i+n]++] = i ;
        }
        else
        {
            cap[i][i+n] = 1 ; // 1ibar1 jaowa asa kora jabe
            adj[i][deg[i]++] = i+n;
            adj[i+n][deg[i+n]++] = i ;
        }
    }
    for ( i = 1 ; i <= n ; i++ )
    {
        for ( j = i+1 ; j <= n ; j++ ) // input ascending order e sort korei thakbe
        {
            if( inp[j].value - inp[i].value <= limit )
            {
                cap[i+n][j] = 2 ;
                adj[i+n][deg[i+n]++] = j ;
                adj[j][deg[j]++] = i ;
            }

        }
    }
    for ( i = 1 ; i <= n ; i++ )
    {
        if( inp[i].value <= limit )
        {
            cap[scr][i] = 2 ;
            adj[scr][deg[scr]++] = i ;
            adj[i][deg[i]++] = scr ;
        }
        if( d - inp[i].value <= limit )
        {
            cap[i+n][sink] = 2 ;
            adj[sink][deg[sink]++] = i+n ;
            adj[i+n][deg[i+n]++] = sink ;
        }
    }

}
void solve(int cs)
{

   input();
   int ans = d  , low = 0 , high = d ;
   int scr = 0 , sink = n+n+1 ;
   while( high >= low )
   {
       int mid  = ( low + high )/2 ;
       build(mid); // constuct graph
       if( dinic(scr,sink) >= 2 )
       {
           ans = mid ; // aro komano jay kina
           high = mid - 1 ;

       }
       else low = mid+1;
   }

   printf("Case %d: %d\n",cs,ans);




}
int main()
{

    int cs , t ;
    read(t);
    for ( cs = 1 ; cs <=t ; cs++ )
    {

        solve(cs);
    }

    return 0;
}
/*
2
5 3.5
1 1 1 1
2 3 0 1
3 5 1 1
5 1 1 1
5 4 0 1
3 1.1
-1 0 5 10
0 0 3 9
2 0 1 1

*/
