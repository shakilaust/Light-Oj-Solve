
 //BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopner soman boro
 Author :: Shakil Ahmed
.............AUST_CSE27.........
 prob   ::
 Type   ::
 verdict::
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>
#include <set>
#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <list>
#include <map>
#include <queue>
#include <sstream>
#include <utility>
#define pf(a) printf("%d\n",a)
#define pf2(a,b) printf("%d %d\n",a,b)
#define pfcs(cs,a) printf("Case %d: %d\n",cs,a)
#define sc(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
#define pi acos(-1.0)
#define ff first
#define LL long long
#define ss second
#define rep(i,n) for(i = 0; i < n; i++)
#define REP(i,n) for(i=n;i>=0;i--)
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define ROF(i,a,b) for(int i = a; i >= b; i--)
#define re return
#define QI queue<int>
#define SI stack<int>
#define pii pair <int,int>
#define MAX
#define MOD
#define INF 1<<30
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define memo(a,b) memset((a),(b),sizeof(a))
#define G() getchar()
#define MAX3(a,b,c) max(a,max(b,c))

double const EPS=3e-8;
using namespace std;


template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }

const int N = 100005 ;
int inp[N], a[N] , Lis[N] , Lds[N] , n , b[N];
void LIS()
{
       int i , tmp , low , lis = 0 ;

       a[0] = -INF ;
       a[n] = INF ;
       for ( i = 0 ; i < n ; i++ )
       {
              low = lower_bound( a , a+n+1 , inp[i] ) - a;
              a[low] = inp[i] ;
              lis = max ( lis , low );
              Lis[i] = lis ;

       }
}
void LDS()
{
       int i , tmp , low , lds = 0 ;

       b[0] = -INF ;
       b[n] = INF;
       for ( i = n-1 ; i >=0 ; i-- )
       {
              low = lower_bound( b , b+n+1 , inp[i] ) - b;
              b[low] = inp[i] ;
              lds = max ( lds , low );
              Lds[i] = lds ;

       }
}
int solve()
{
       int i , ans = 0 ;
       LIS();
       LDS();
       for ( i = 0 ; i < n ; i++ ) ans = max ( ans , min(Lis[i],Lds[i]));
       //printf("ans :: %d\n",ans) ;
       return ( 2 * ans );

}
void input()
{
       int i ;
       for ( i = 0 ; i < n ; i ++ ) scanf("%d",&inp[i]) , a[i] = b[i] = INF;

}
int main()
{  int cs , t ;
   scanf("%d",&t);
   for( cs = 1 ; cs <= t  ; cs++ )
   {      scanf("%d",&n);
          input();
          printf("Case %d: %d\n",cs,solve()-1);
   }
}
