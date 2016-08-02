
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define EPS 1e-8
using namespace std;
int n,G[105],cs;
double dp[105];
double Dp(int pos)
{   int i;
    if(pos>n) return 0;
    int ct=min(6,n-pos);
    if((int)dp[pos]) return dp[pos];
    dp[pos]=G[pos];
    for(i=pos+1;i<=pos+ct;i++)
   {
    dp[pos]+=(Dp(i)*(1.0/ct));
   }
    return dp[pos];
}
void solve()
{   int i;
    scanf("%d",&n);
    memset(dp,0,sizeof(dp));
    for(i=1;i<=n;i++) scanf("%d",&G[i]);
    printf("Case %d: %lf\n",cs,Dp(1)+EPS);
}
int main()
{
    int t;
    scanf("%d",&t);
    for(cs=1;cs<=t;cs++) solve();
}
