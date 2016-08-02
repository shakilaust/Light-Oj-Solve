

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
template <class T> inline T bigmod(T p,T e,T M)
{
    if(e==0)return 1;
    if(e%2==0){LL t=bigmod(p,e/2,M);return (T)((t*t)%M);}
    return (T)((LL)bigmod(p,e-1,M)*(LL)p)%M;
}

template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

/* **************************************  My code start here ****************************************** */
LL dp[(1<<13)+5][15][15];
LL ans[15] ;
int n , q , r , k ;
int notok[15][15];
LL DP(int mask , int last , int left)
{
    if(mask == (( 1 << n ) -1 )) return (LL) 1;
    LL &ret = dp[mask][last][left];
    if(ret!=-1) return ret;
    ret = 0 ;
    int i ;
    for ( i = 0 ; i<n ; i++ )
    {
        if( mask & (1 << i )) continue;
        if ( left - notok[last][i+1] < 0 ) continue;
        ret += DP( mask | ( 1 << i) , i+1 , left - notok[last][i+1] ) ;
    }
    return ret;
}
int main()
{
       // freopen("input.txt","r",stdin);
       int cs , t , i;
       scanf("%d",&t);
       for ( cs = 1 ; cs <= t ; cs++ )
       {
           memo(notok,0);
           printf("Case %d:\n",cs);
           scanf("%d %d %d",&n,&k,&q);
           int x , y ;
           for ( i = 1 ; i <= n ; i++ )
           {
                scanf("%d",&y);
               while(y--)
               {
                   scanf("%d",&x);
                   notok[i][x] = 1;
               }
           }
              memo(dp,-1);
           for ( i = 0 ; i <= n ; i++ ) {

            ans[i] = DP(0,0,i);
           }
            int idx ;
           while(q--)
           {
               cin >> r ;
               if(k==0) idx = n ;
               else
               {
                   idx = ( r / k ) ;
                   if(idx>n) idx = n ;
               }
               printf("%lld\n",ans[idx]);
           }

       }
       return 0;

}
