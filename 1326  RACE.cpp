
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
#define MOD  10056
#define INF 1LL<<31-1
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define memo(a,b) memset((a),(b),sizeof(a))
#define G() getchar()


using namespace std;


template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
int dp[1005][1005],ans[1005];
void pre()
{
       int i,j;
       //memo(dp,0);
       dp[1][1]=1;
       for(i=2;i<=1000;i++)
       {
              dp[i][1]=1;
              for(j=2;j<=i;j++)
                 dp[i][j]=((dp[i-1][j-1]+dp[i-1][j])*j)%MOD;
       }
       for(i=1;i<=1000;i++)
       {
              ans[i]=0;
              for(j=1;j<=i;j++)
              ans[i]+=dp[i][j];
              ans[i]%=MOD;
       }
}


int main()
{

    //freopen("in.txt", "r", stdin);
    pre();
    int cs,T;
    sc(T);
    FOR(cs,1,T)
    {
           int n;
           sc(n);
           pfcs(cs,ans[n]);
    }


}
