
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int dp[105][105],x[105],width,cs,k,n;
int DP(int pos,int move)
{   int ans;

    if(pos>=n || move>=k) return 0;
    if(dp[pos][move]!=-1) return dp[pos][move];
    //printf("pos:: %d move:: %d\n",pos,move);
    int i,count=0;
    for(i=0;i+pos<n;i++)
    {
        if(x[pos]+width<x[pos+i]) break;
        count++;

    }

     ans=max(count+DP(pos+i,move+1),DP(pos+1,move));
    // printf("ans:: %d\n",ans);
  // amra ei move nibo ba nibo na, then highest result
   // eida na korleo hobar kotha
    return dp[pos][move]=ans;
}
void solve()
{    int in,i;
    scanf("%d %d %d",&n,&width,&k);
    for(i=0;i<n;i++)
      scanf("%d %d",&in,&x[i]);
      sort(x,x+n);

      memset(dp,-1,sizeof(dp));
      printf("Case %d: %d\n",cs,DP(0,0));

}
int main()
{  // freopen("input.txt","r",stdin);
    int t;
    scanf("%d\n",&t);

    for(cs=1;cs<=t;cs++)
    {
        solve();
    }
}
