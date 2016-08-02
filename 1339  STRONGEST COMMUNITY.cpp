
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
const int MX = 1e5 + 9 ;
int tree[MX*5] , start[MX] , ComSum[MX] , Inp[MX] , Id[MX] , n , c , q , idx = 0 ;
void ini(int node , int low , int high )
{
    if( low == high )
    {
        tree[node] = ComSum[low];
        return ;
    }
    int mid = ( low + high ) / 2 ;
    ini(node<<1 , low , mid );
    ini( (node<<1)|1 , mid + 1 , high );
    tree[node] = max( tree[node<<1] , tree[(node<<1)|1] ) ;
}
int Query(int node , int lo , int hi , int x , int y )
{
    if( x > hi || y < lo ) return 0 ;
    if ( x <= lo && y >= hi )
    {
        return tree[node];
    }
    int mid = ( lo + hi ) / 2 ;
    return max( Query(node << 1 , lo , mid , x , y ) , Query((node<<1)|1 , mid + 1 , hi , x , y ));
}
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
   int cs , t = II ;
   for ( cs = 1 ; cs <= t ; cs++ )
   {
       n = II ;
       c = II ;
       q = II ;
       int i , j ;
       rep(i,n)
       {
           Inp[i] = II ;
       }
       idx = 0 ;
       for ( i = 0 ; i < n ; i++ )
       {
           int cnt = 1 ;
           for ( j = i + 1 ; j < n ; j++ )
           {
               if( Inp[i] ==  Inp[j] )
               {
                   Id[j] = idx ;
                   cnt++;
               }
               else break ;
           }
           Id[i] = idx ;
           start[idx] = i ;
           i = j - 1 ;
           ComSum[idx++] = cnt ;
       }
       ini( 1 , 0 , idx-1 );
       printf("Case %d:\n",cs);
     //  int q = II ;
       for ( i = 0 ; i < q ; i++ )
       {
           int x = II ;
           int y = II ;
           x-- , y-- ;
           if( Inp[x] == Inp[y] ) printf("%d\n", y - x + 1);
           else
           {
               int p1 = Id[x] , p2 = Id[y] ;
             //  printf(" p1 :: %d comSum[p1] :: %d start[p1] :: %d x :: %d\n ",p1,ComSum[p1],start[p1],x);
              // printf(" p2 :: %d comSum[p2] :: %d start[p2] :: %d y :: %d\n",p2,ComSum[p2],start[p2],y);
               int mx = max( ComSum[p1] -( x -  start[p1]  ), y -  start[p2] + 1 );

               p1++;
               p2--;
               if( p1 <= p2 ) mx =  max( mx , Query(1,0,idx-1 , p1,p2 ));
               printf("%d\n",mx);
           }

       }
   }
    return 0;
}
