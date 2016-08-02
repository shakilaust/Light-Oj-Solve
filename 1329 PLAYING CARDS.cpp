
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
ull dp[15][15][15][15][5] ;
int vis[15][15][15][15][5] , cs , n ;
char str[10];
int A[5] , freq[15] ;
int chk( char c )
{
    if( c == 'T' ) return 10 ;
    if( c == 'J' ) return 11 ;
    if( c == 'Q' ) return 12 ;
    if( c == 'K' ) return 13 ;
    if( c == 'A' ) return 1 ;
    return (c - '0');
}
ull DP( int one , int two , int three , int four , int lst )
{
  // printf(" %d %d %d %d %d\n",one,two,three,four,lst);
    if( !one && !two && !three && !four ) return 1 ;
    ull &ret = dp[one][two][three][four][lst];
    int &v = vis[one][two][three][four][lst];
    if( v  ) return ret ;
    v = 1 ;
    ret = 0 ;
    if( one )
    {
        // printf("one\n");
        if( lst == 2 ) ret += ( one - 1) * DP( one - 1 , two , three , four , 1 );
        else ret += ( one ) *  DP( one - 1 , two , three , four , 1 );
    }
    if( two )
    {
        if( lst == 3 ) ret += (ull) 2 * ( two - 1 ) * DP( one + 1 , two - 1 , three , four , 2);
        else ret += (ull) 2 * ( two ) * DP( one + 1 , two - 1 , three , four , 2 );
    }
    if( three )
    {
        if( lst == 4 ) ret += (ull) 3 * ( three - 1 ) * DP( one , two + 1 , three - 1 , four , 3 );
        else ret += (ull) 3 * ( three ) * DP( one , two + 1 , three -1 , four , 3 );
    }
    if(four ) ret += (ull) 4 * ( four ) * DP( one , two , three + 1 , four - 1 , 4 );
    return ret ;
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
             n = II ;
             ms( A , 0 );
             ms( freq , 0 );
             rep( i , n )
             {
                 scanf("%s",str);
                 freq[chk(str[0])]++;
             }
             for( int i = 1 ; i <= 13 ; i++ ) A[freq[i]]++;

             printf("Case %d: %llu\n",cs,DP(A[1],A[2],A[3],A[4],0));

         }



    return 0;
}
/*
2
4 AC KC QC JC
6 AC AD AS JC JD KD
*/
