
#include <stdio.h>
#include <string.h>
#define max(a,b) ((a)>=(b)? (a) : (b))
int a[1005],dp[1005];
int Dp(int pos,int end)
{
       if(pos>end) return 0;
       if(dp[pos]!=-1) return dp[pos];
       dp[pos]=max(Dp(pos+2,end)+a[pos],Dp(pos+1,end));
       return dp[pos];
}
int main()
{
       int t,cs,n,i;
       scanf("%d",&t);
       for(cs=1;cs<=t;cs++)
       {     scanf("%d",&n);
             for(i=0;i<n;i++) scanf("%d",&a[i]);
              memset(dp,-1,sizeof(dp));
              int ans=Dp(0,n-2);
              memset(dp,-1,sizeof(dp));
              ans=max(Dp(1,n-1),ans);
              printf("Case %d: %d\n",cs,ans);

       }
}
