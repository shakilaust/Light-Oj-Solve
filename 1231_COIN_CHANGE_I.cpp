
#include <stdio.h>
#include <string.h>
#define MOD 100000007

 int s[105],C[105],Dp[1010][55],M,N,t;
 int solve(int total,int idx)
 {
     if(idx>=M)
     {
         if(total==N) return 1;
         else return 0;
     }
     if(total>N) return 0;
     if(total==N) return 1;
     if(Dp[total][idx]!=-1) return Dp[total][idx];
     int ret=0;

	for(int take=1;take<=C[idx];take++)
	{
	    if(total+s[idx]*take<=N)
		ret+=solve(total+s[idx]*take,idx+1)%MOD;
		else break;
	}
	ret+=solve(total,idx+1)%MOD;
	return Dp[total][idx]=ret%MOD;
 }

int main()
{
   scanf("%d",&t);
   for(int kase=1;kase<=t;kase++)
   {
   memset(Dp,-1,sizeof(Dp));
   scanf("%d %d",&M,&N);
   for(int i=0;i<M;i++)  scanf("%d",&s[i]);
   for(int i=0;i<M;i++) scanf("%d",&C[i]);
   int res=solve(0,0);
   printf("Case %d: %d\n",kase,res);
   }
   return 0;
}
