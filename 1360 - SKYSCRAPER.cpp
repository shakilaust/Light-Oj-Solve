
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

const int MAXN = 30000+5 ;
struct abc
{
       int start , end , cost;
} inp [ MAXN ] ;

int Indxing [ MAXN ]  ;
LL dp[ MAXN ];

bool cmp ( abc A , abc B )
{      if(A.end == B.end ) return A.start < B.start ;
       return A.end < B.end ;
}
LL solve(int n )
{
       sort ( inp+1, inp+n+1 , cmp );
       sort (Indxing+1,Indxing+n+1);
       int i;
       memo(dp,0);
       inp[0].start = inp[0].end = -1;
       Indxing[0] = -1;
       LL ans = -1;
       for ( i = 1 ; i <= n ; i++ )
       {
              int idx = lower_bound (Indxing , Indxing+i , inp[i].start ) - Indxing ;
              if( idx && Indxing[idx] >= inp[i].start ) idx--;
              dp[i] = dp[idx] + inp[i].cost ;
              dp[i] = max ( dp[i] , dp[i-1] );
              ans = max ( ans , dp[i] );
       }
       return ans ;
}
int main()
{
       int cs, t , i , n;
       scanf("%d",&t);
       for ( cs = 1 ; cs <= t ; cs++ )
       {
              scanf("%d",&n);
              for ( i = 1; i <= n ; i++ )
              {
                     scanf("%d %d %d",&inp[i].start , &inp[i].end , &inp[i].cost ) ;
                     inp[i].end += inp[i].start - 1 ;
                     Indxing[i] = inp[i].end ;
              }
              printf("Case %d: %lld\n",cs,solve(n));
       }

}
