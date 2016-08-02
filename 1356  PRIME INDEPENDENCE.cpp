
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
int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

/* **************************************  My code start here ****************************************** */
const int NX = 500000 + 10;
const int MX = 40000 + 10 ;
const int INF = 1 << 29 ;
int check[NX] , prime[NX] , id , n ;
int inp[MX];
vector < int > adj[MX];
int dist[MX] , match[MX] ;
int q[NX] ,  fnd[NX] ;
void ini()
{
    rep( i , n + 2 ) { adj[i].clear(); match[i] = 0 ; }
    ms( fnd , -1 );
}
void Pre()
{
    prime[id++] = 2 ;
    int i , j ;
    for ( i = 3 ; i * i < NX ; i+=2 )
    {
        if( check[i] == 0 )
        {
            prime[id++] = i ;
            for ( j = i * i ; j < NX ; j += ( 2 * i ) ) check[j] = 1 ;
        }
    }
    while( i < NX )
    {
        if( check[i] == 0 ) prime[id++] = i ;
        i += 2 ;
    }
    // cout << " toto " << id << endl ;
}
bool bfs()
{
    int f = 0 , b = 0 , i ;
    For( i , n )
    {
        if( match[i] == 0 )
        {
            dist[i] = 0 ;
            q[f++] = i ;
        }
        else dist[i] = INF ;
    }
    dist[0] = INF ;
    while( b < f )
    {
        int x = q[b++] ;
        if( x == 0 ) continue ;
        int sz = adj[x].size();
        rep( i , sz )
        {
            int y = adj[x][i];
            if( dist[match[y]] == INF )
            {
                dist[match[y]] = dist[x] + 1 ;
                q[f++] = match[y];
            }
        }
    }
    return dist[0] != INF ;
}
bool dfs(int x)
{
    if( x )
    {
        int sz = adj[x].size();
        rep( i , sz )
        {
            int y = adj[x][i];
            if( dist[match[y]] == dist[x] + 1 && dfs(match[y]))
            {
                match[x] = y ;
                match[y] = x ;
                return 1 ;
            }
        }
        dist[x] = INF ;
        return 0 ;
    }
    return 1 ;
}
int hopcropt()
{
    int matching = 0 ;
    while( bfs() )
    {
        for( int i = 1 ; i <= n ; i++ )
        {
            if( match[i] == 0 && dfs(i) )
            {
                matching++;
            }
        }
    }
    return n - matching ;
}
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
   Pre();
   int cs , t = II ;
   for ( cs = 1 ; cs <= t ; cs++ )
   {
      n = II ;
      ini();
      int mx = -1 ;
      For( i , n )
      {
          inp[i] = II ;
          fnd[inp[i]] = i ;
          if( mx == -1 || inp[i] > mx ) mx = inp[i];

      }
      For( i , n )
      {
          rep( j  , id )
          {
              int y = prime[j] * inp[i];
              if( y > mx ) break ;
              if(  fnd[y] != -1 )
              {
                  adj[fnd[y]].pb(i);
                  adj[i].pb(fnd[y]);
              }
          }
      }

      printf("Case %d: %d\n",cs,hopcropt());


   }



    return 0;
}
