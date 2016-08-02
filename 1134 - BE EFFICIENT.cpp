
#include <stdio.h>
#define rep(i,n) for(i=0;i<n;i++)
#define MAX 100005
int dp[MAX],a[MAX] ,n,m,cs,t,i;;
long long int sum=0,ans=0;
int main()
{

       scanf("%d",&t);
       for(cs=1;cs<=t;cs++)
       {
              scanf("%d %d",&n,&m);
              rep(i,m) dp[i]=0;
              dp[0]=1;
              sum=ans=0;
              rep(i,n)
              {      scanf("%d",&a[i]);
                     sum=(sum+a[i])%m;
                     ans+=dp[sum];
                     dp[sum]++;
              }
              printf("Case %d: %lld\n",cs,ans);
       }
}
