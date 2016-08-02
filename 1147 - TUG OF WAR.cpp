
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
int n , sum ;
long long int dp[100000+5]; // almost 64 bits , we need just 50 as limit is 100
int w[105];
void Clear()
{
       int i , j ;

              for ( j = sum/2+sum%2 ; j>=0 ; j-- ) dp[j] = 0 ;

}

int main()
{
       int cs , t , i , j , k , x , y;
       scanf("%d",&t);
       for ( cs = 1; cs<= t ; cs++ )
       {
              scanf("%d",&n);
              sum = 0 ;
              for ( i = 0 ; i < n ; i++  )
              { scanf("%d",&w[i]);
                sum += w[i];
              }
              int best = ( sum/2 + sum%2 );
             // Clear();
             memo(dp,0);
              dp[0] = 1;
              for ( i = 0 ; i < n ; i++ )
              {
                     int x = w[i];

                            for( k = sum/2 ; k >= x ; k-- )
                            {
                                   dp[k] = dp[k] | ( dp[k-x]<<1) ;
                            }

              }
              x = ( n+1)/2;
              y = (n) / 2;
              long long mul = 1;
              for ( i = sum/2 ; i>=0 ; i-- )
              {
                     if((dp[i] & ( mul << x )) || (dp[i] & ( mul << y ))) break;
              }
              printf("Case %d: %d %d\n",cs, i , sum - i );


       }

}
