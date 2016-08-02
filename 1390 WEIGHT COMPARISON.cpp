
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

const int NX = 5005 ;
const int MX = NX / 32 + 4 ;

int isPossible[ NX ][ MX ];
int sz , n , m  ;

vector < pii > ans ;

int toposortorder[ NX ] , idx , In[ NX ] ;

vector < int > graph[ NX ] ;

void ini()
{
    rep( i , n + 2 )
    {
        graph[i].clear();
        In[i] = 0 ;

    }
    ans.clear();
}

void topsort()
{
    int h = 0 , t = 0 ;
    for( int i = 1 ; i <= n ; i++ )
    {
      //  printf(" i :: %d In :: %d\n" , i , In[i] );
        if( In[i] == 0 ) toposortorder[ t++ ] = i ;
    }
    while( h < t )
    {
        int u = toposortorder[ h++ ] ;

        int ssz = graph[ u ].size();
        rep( i , ssz )
        {
            int v = graph[ u ][ i ];
           // printf(" U :: %d V :: %d In[v] :: %d\n" , u , v , In[v] );
            In[v]--;
            if( In[v] ) continue ;
            toposortorder[ t++ ] = v ;
        }
    }
  /*  for ( int i = 0 ; i < n ; i++ )
    {
        printf("%d ", toposortorder[i] );
    }
    puts(" this is order "); */
}

void solve()
{
    for( int i = n - 1 ; i >= 0 ; i-- )
    {
        int u = toposortorder[ i ];
       // printf(" now :: %d\n" , u );
        for( int j = 0 ; j < sz ; j++ ) isPossible[ u ][ j ] = 0 ;
        int ssz = graph[u].size();
        for ( int j = 0 ; j < ssz ; j++ )
        {
            int v = graph[u][j];
            for ( int k = 0 ; k < sz ; k++ ) isPossible[ u ][ k ] |= isPossible[ v ][ k ];
        }
        for ( int j = 0 ; j < ssz ; j++ )
        {
            int v = graph[ u ][ j ];
            if( isPossible[ u ][ v / 32 ] & ( 1 << ( v % 32 ) ) ) continue ;
            isPossible[ u ][ v / 32 ] |= ( 1 << ( v % 32 ) ) ;
            ans.pb( mp( u , v ) );
        }
    }
    sort( ans.begin() , ans.end() );
}
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being

    int cs , t = II ;
    for ( cs = 1 ; cs <= t ; cs++ )
    {

           n = II , m = II ;
           sz = ( ( n + 32 ) / 32 );
           ini();
           rep( i , m )
           {
               int x = II , y = II ;
               graph[x].pb(y);
               In[y]++;
           }

           topsort();
           solve();
           int anssz = ans.size();
           printf("Case %d: %d\n",cs,anssz );
           rep( i , anssz )
           {
               printf("%d %d\n",ans[i].ff, ans[i].ss);
           }




    }
    return 0;
}

// tkirchner@appirio.com
