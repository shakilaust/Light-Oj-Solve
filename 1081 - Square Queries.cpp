
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
int ST[NX][NX][20] , n , q ;
int lg[NX];
int MX( int a , int b)
{
    return max( a , b );
}
void Pre()
{
    lg[0] = -1 ;
    for ( int i = 1 ; i < NX ; i++ )
    {
        lg[i] = lg[i>>1] + 1 ;
    }
}
void Cal()
{
    for ( int u = 1 ; u <= lg[n] ; u++ )
    {
        int lim = n - ( 1 << u ) + 1;
        for ( int i = 0 ; i < lim ; i++ )
        {
            for ( int j = 0 ; j < lim ; j++ )
            {
                ST[i][j][u] = MX( ST[i+(1<<(u-1))][j+(1<<(u-1))][u-1] , MAX3(ST[i+(1<<(u-1))][j][u-1] , ST[i][j+(1<<(u-1))][u-1] ,ST[i][j][u-1]));
             //   printf("i :: %d j :: %d u :: %d val :: %d\n" , i , j , u , ST[i][j][u]);
            }

        }


    }
}
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
   Pre();
   int cs , t = II ;
   for ( cs = 1 ; cs <= t ; cs++ )
   {
       scanf("%d %d",&n,&q);
      // printf("%d %d\n",n,q);
       for ( int i = 0 ; i < n ; i++ )
       {
           for ( int j = 0 ; j < n ; j++ )
           {
               scanf("%d",&ST[i][j][0]);
               //cout << " paichi " <<  i << " " << j << " val " << ST[i][j][0] << endl ;
           }

       }
       Cal();
       printf("Case %d:\n",cs);
       while(q--)
       {
           int x = II , y = II , lim = II ;
           x--,y--;
           int u = lg[lim];
           int ans = MX( ST[x][y][u] , MAX3(ST[x+lim-(1<<u)][y][u] , ST[x][y+lim-(1<<u)][u] , ST[x+lim-(1<<u)][y+lim-(1<<u)][u]));
           printf("%d\n",ans);
       }
   }


    return 0;
}
