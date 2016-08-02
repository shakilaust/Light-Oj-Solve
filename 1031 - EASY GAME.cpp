
#include <stdio.h>
#include <string.h>
#define INF 1<<29
#define max(a,b) ( (a) > (b) ? a : b)
int a[105],dp[105][105];
int DP(int L,int R)
{      int i,temp=-INF;
       if(L>R) return 0;
       if(L==R) dp[L][R]=a[R]-a[L-1];
       if(dp[L][R]!=-1) return dp[L][R];

       for(i=L;i<=R;i++)
        temp=max(temp,a[i]-a[L-1]-DP(i+1,R));
       for(i=R;i>=L;i--)
       temp=max(temp,a[R]-a[i-1]-DP(L,i-1));
       return dp[L][R]=temp;


}
int main()
{
       int cs,t,i,n;
       scanf("%d",&t);
       for(cs=1;cs<=t;cs++)
       {
               scanf("%d",&n);
               a[0]=0;
               for(i=1;i<=n;i++)
               {
                      scanf("%d",&a[i]);
                      a[i]+=a[i-1];
               }
             memset(dp,-1,sizeof(dp));
             printf("Case %d: %d\n",cs,DP(1,n));

       }
}
