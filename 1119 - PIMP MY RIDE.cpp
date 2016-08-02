
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define FIND(N,pos) ( N & (1 << (pos) ) )
using namespace std;
int SET(int N,int pos) { return N= N | (1<<pos) ;}
int n,w[20][20],dp[(1<<15)+2];
int bitmask(int mask)
{
    if(mask==(1<<n)-1) return 0;
    if(dp[mask]!=-1) return dp[mask];
    int i,j,mx=1<<29;
    for(i=0;i<n;i++)
    {   if(!FIND(mask,i))
        {
            int price=w[i][i];
              for(j=0;j<n;j++)
                {
                      if(i!=j && FIND(mask,j))
                      {   price+=w[i][j];

                      }

                }
            int ret=price+bitmask(SET(mask,i));
            mx=min(mx,ret);
        }
    }
    return dp[mask]=mx;
}
int main()
{ //  freopen("input.txt","r",stdin);
    int tc,kase;
    scanf("%d",&tc);
    for(kase=1;kase<=tc;kase++)
    {   int i,j;
        scanf("%d",&n);
        for(i=0;i<n;i++)
           for(j=0;j<n;j++)
              scanf("%d",&w[i][j]);
        memset(dp,-1,sizeof(dp));
        printf("Case %d: %d\n",kase,bitmask(0));
    }

}
