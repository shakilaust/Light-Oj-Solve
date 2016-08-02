
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
const int NX = 50000 + 10 ;
char T[NX] , P[NX] ;
Long dp[NX] , matchLeft[NX] , matchRight[NX] ;
int pi[NX] ,f[NX] ;
void KmpMatch(char *t , char *p , Long *m)
{

   int tt = strlen(t);
   int pp = strlen(p);
   int k = 0  , i = 0 ;
   pi[0] = pi[1] = 0 ;
   if( pp > 1 ) dp[1] = 1 ;

    //failure-func
    for( i = 2 ; i < pp ; i++ )
    {
        while( k > 0 && p[i-1] != p[k] ) k = pi[k];
        if( p[i-1] == p[k] ) k++;
        pi[i] = k ;
        dp[i] = dp[k] + 1 ;

    }

    k = 0 ;
    //pattern look-up
    for ( i = 0 ; i < tt ; i++ )
    {
        while( k > 0 && t[i] != p[k] ) k = pi[k];
        if( p[k] == t[i] ) k++;
        m[i] = dp[k];
        if( k == pp - 1 ) k = pi[k];
    }



}
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
  // ms( vis , -1 );
  //  cout << fixed << setprecision(10);
     int cs , t = II ;
     for ( cs = 1 ; cs <= t ; cs++ )
     {
         scanf("%s %s",T,P);
         int tt = strlen(T);
         int pp = strlen(P);
         KmpMatch(T,P,matchLeft);
         reverse(T,T+tt);
         reverse(P,P+pp);
         KmpMatch(T,P,matchRight);
         reverse(matchRight , matchRight + tt );
         Long ans = 0 ;
         for ( int  i = 0 ; i < tt  - 1; i++ ) ans += (1ll * matchLeft[i] * matchRight[i+1]);
         printf("Case %d: %lld\n",cs,ans);
     }


    return 0;
}
/*
2
AAA
AAAA
AAAA
AAA
*/
