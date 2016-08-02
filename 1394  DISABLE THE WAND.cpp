
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
const int MX = 35 ;
Long st , en , maxone , maxdiff , ideal , A ;
pll dp[MX][MX][MX][3][7][2];
bool vis[MX][MX][MX][3][7][2];
pll DP(int idx , int one , int diff , int mod3 , int mod7 , int isSmall )
{
   // printf("")


    if( diff > maxdiff || one > maxone ) return mp(0,0);
    if( idx < 0 )
    {
       // printf("mod3 :: %d mod7::%d\n",mod3,mod7);
        if( !mod3 && mod7 ) return make_pair(0ll,1ll);
        else return mp(0ll,0ll);
    }
     pll &ret = dp[idx][one][diff][mod3][mod7][isSmall];

     if( vis[idx][one][diff][mod3][mod7][isSmall]) return ret ;
     vis[idx][one][diff][mod3][mod7][isSmall] = 1 ;
   // ret = mp(0,0);
    pll tmp , rt ;
    int cur = (ideal & ( 1ll << idx )) ? 1 : 0 ;
    if( isSmall || (A &( 1ll << idx )) )
    {
       // printf("here\n");
        // 1 bosai
        tmp = DP(idx-1,one+1 , diff + ( cur ^ 1 ) , ( mod3 + ( 1ll << idx ))%3ll , (mod7 + ( 1ll << idx))%7ll , isSmall );
        rt.ff += (( 1ll << idx)*tmp.ss) + tmp.ff ;
        rt.ss += tmp.ss ;
        // o bosai
         // cout << ret.ff << " " << tmp.ss << " " << endl ;
        tmp = DP(idx-1,one,diff+cur,mod3,mod7,1);
        rt.ff += tmp.ff ;
        rt.ss += tmp.ss ;

    }
    else
    {
        tmp = DP(idx-1,one,diff+cur,mod3,mod7,isSmall);
        rt.ff += tmp.ff ;
        rt.ss += tmp.ss ;
    }
  //  printf("idx :: %d == ",idx);
   // cout << rt.ff << endl ;
    return ret = rt ;
}
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
   int cs , t = II ;
   for ( cs = 1 ; cs <= t ; cs++ )
   {
       st = LL , en = LL , maxone = LL , ideal = LL , maxdiff = LL ;
       //ms(dp,-1);
       ms(vis,0);
       A = en ;
       pll two = DP(32,0,0,0,0,0) ;
       if( st == 0 ) printf("Case %d: %lld\n",cs,two.ff);
       else
       {
           A = st - 1;
           ms(vis,0);
           pll one = DP(32,0,0,0,0,0) ;
          // cout << one.ff << " " << two.ff << endl ;
           printf("Case %d: %lld\n",cs,two.ff-one.ff);
       }
   }


    return 0;
}
