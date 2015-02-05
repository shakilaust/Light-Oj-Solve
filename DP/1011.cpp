#include <stdio.h>
#include <string.h>
#include <algorithm>
#define FIND(N,pos) ((N) & (1<< (pos)))
using namespace std;
int SET(int N,int pos) { return N=N | (1<<pos); }
int dp[(1<<18)],w[20][20],N;
int DP(int i,int mask)
{    if(mask==(1<<N)-1 || i>=N) return 0;
     if(dp[mask]!=-1) return dp[mask];
     int ax=0,j;
     for(j=0;j<N;j++)
         if(!FIND(mask,j))
            ax=max(ax,w[i][j]+DP(i+1,SET(mask,j)));
     dp[mask]=ax;
     return dp[mask];
}
int main()
{ //  freopen("input.txt","r",stdin);
    int tc,kase;
    scanf("%d",&tc);
    for(kase=1;kase<=tc;kase++)
    {     int i,j;
          scanf("%d",&N);
          for(i=0;i<N;i++)
             for(j=0;j<N;j++)
                 scanf("%d",&w[i][j]);
            memset(dp,-1,sizeof(dp));
            printf("Case %d: %d\n",kase,DP(0,0));
 
    }
}
