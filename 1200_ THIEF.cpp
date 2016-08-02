
//BISMILLAHIRRAHMANIRRAHIM
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#define INF 1<<29
#define rep(i,n) for(i=0;i<n;i++)
#define FOR(i,j,k) for(i=j;i<=k;i++)
int cost[105],weight[105],dp[105][10005],W,n;

using namespace std;
int knapshek(int item,int w)
{
       if(item==n) return 0;
       if(w>W) return 0;

       if(dp[item][w]!=-1) return dp[item][w];
       int profit1=0,profit2;
       if(w+weight[item]<=W)
       profit1=max(cost[item]+knapshek(item+1,w+weight[item]),cost[item]+knapshek(item,w+weight[item]));
       else profit1=0;
       profit2=knapshek(item+1,w);
       dp[item][w]=max(profit1,profit2);
       return dp[item][w];
}
void solve()
{
       int sum=0,i,j;
       scanf("%d %d",&n,&W);
       rep(i,n)
       {      int k;
              scanf("%d %d %d",&cost[i],&k,&weight[i]);
              sum+=k*weight[i];
       }
       if(sum>W) puts("Impossible");
       else if(sum==W) puts("0");
       else
       {
              W-=sum;
              memset(dp,-1,sizeof(dp));

              printf("%d\n",knapshek(0,0));
       }


}

int main()
{
    int cs,t;
    scanf("%d",&t);
    for(cs=1;cs<=t;cs++)
    {
           printf("Case %d: ",cs);
           solve();
    }
}
