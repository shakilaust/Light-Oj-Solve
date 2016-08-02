
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
const int MX = 105 ;
int deg[MX] , adj[MX][MX] , prev[MX] , cap[MX][MX] , q[MX*MX*MX] , n , m;
int dinic(int scr , int sink)
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
void solve(int cs)
{

  map < string , int > mark ;
  mark[ "XXL" ]  = 1 ;
  mark[  "XL" ]  = 2 ;
  mark[  "L"  ]  = 3 ;
  mark[  "M"  ]  = 4 ;
  mark[  "S"  ]  = 5 ;
  mark[  "XS" ]  = 6 ;// XXL, XL, L, M, S
  int i ;
  memo(deg,0);
  memo(cap,0);
  read(n) , read(m) ;
  int sink = 6 + m + 1 ;
  for ( i = 1 ; i <= 6 ; i++ )
  {
      cap[0][i] = n ;
      adj[0][deg[0]++] = i ;
      adj[i][deg[i]++] = 0 ;
  }

  string a , b ;
  int x , y , id;
  for ( i =  1; i <= m ; i++ )
  {
      cin >> a >> b ;
      x = mark[a];
      y = mark[b];
      id = i + 6 ;

      cap[x][id] = 1;
      cap[y][id] = 1 ;
      adj[id][deg[id]++] = x;
      adj[x][deg[x]++] = id ;
      adj[id][deg[id]++] = y;
      adj[y][deg[y]++] = id;
      cap[id][sink] = 1 ;
      adj[id][deg[id]++] = sink ;
      adj[sink][deg[sink]++] = id;

  }
  int flow = dinic(0,sink);
  //printf(" flow :: %d\n",flow);
        printf("Case %d: ",cs);
        if(flow==m)puts("YES");
        else      puts("NO");


}
int main()
{
   // ios_base::sync_with_stdio(0); cin.tie(0);
    int cs , t ;
    read(t);
    for ( cs = 1 ; cs <=t ; cs++ )
    {
        solve(cs);
    }

    return 0;
}
/*
3
3 6
L XL
XL L
XXL XL
S XS
M S
M L
1 4
S XL
L S
L XL
L XL
1 1
L M
*/
