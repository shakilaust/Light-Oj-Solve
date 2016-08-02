
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
//Fast Reader
template<class T>inline bool read(T &x){int c=getchar();int sgn=1;while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}for(x=0;~c&&'0'<=c&&c<='9';c=getchar())x=x*10+c-'0'; x*=sgn; return ~c;}

/* **************************************  My code start here ****************************************** */
const int Mx = 500000 + 5;
int dp[2][Mx] , inp[55];
int main()
{
    int cs , t ;
    read(  t ) ;
    for ( cs = 1  ; cs <= t ; cs++ )
    {
        int mid , sum = 0 ,total = 0, prev = 0 , cur = 1, i  , j , n ;
        read(n) ;
        rep(i,n)
        {
            read(inp[i]);
            sum += inp[i];
        }
        mid = sum/2;
        for(i  = 0 ; i <= mid ; i++ ) dp[0][i] = dp[1][i] = -1;
        dp[0][0] = 0 ;
        sort(inp,inp+n);
        for ( i = 0 ; i < n ; i++ )
        {
            for ( j = 0 ; j <= total ; j++ )
            {
                if( dp[prev][j] == -1 ) continue ;
                    if(dp[prev][j]>dp[cur][j]) dp[cur][j] = dp[prev][j];
                    if(j>=inp[i])
                    {
                        if(dp[cur][j-inp[i]] < dp[prev][j] + inp[i])
                        dp[cur][j-inp[i]] = dp[prev][j] + inp[i];
                    }
                    else
                    {
                        if(dp[cur][inp[i]-j] < dp[prev][j] + inp[i] )
                        dp[cur][inp[i]-j] = dp[prev][j] + inp[i] ;
                    }
                    if( j + inp[i] <= mid)
                    if(dp[cur][j+inp[i]] < dp[prev][j] + inp[i] )
                    dp[cur][j+inp[i]] = dp[prev][j] + inp[i];

            }
            swap(cur,prev);
            total = min(total + inp[i] , mid);
        }
       // if(dp[prev][0] > dp[cur][0] ) dp[cur][0] = dp[prev][0] ;
        if(dp[ prev ][0] == 0 ) printf("Case %d: impossible\n",cs);
        else printf("Case %d: %d\n",cs,dp[prev][0]/2);

    }
   return 0;
}
