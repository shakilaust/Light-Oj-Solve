
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MAX 103
#define INF 1<<29
#define memo(a,b) memset(a,b,sizeof(a))
#define FOR(a,b,c) for(a=b;a<=c;a++)
using namespace std;
bool vis[MAX][MAX][MAX];
int dp[MAX][MAX][MAX],len,a[MAX];
#define S(V) V[l][r][idx]
int DP(int l,int r,int idx)
{
       if(idx>len) return 0;
       if(S(vis)) return S(dp);
       S(vis)=1;
       int left=0,right=0,central;
       if(a[l]<=a[idx] && a[idx]<=a[r])
       {
              left=1+DP(idx,r,idx+1);
              right=1+DP(l,idx,idx+1);
       }
       central=DP(l,r,idx+1);
       return S(dp)=max(central,max(left,right));

}
int main()
{
       int cs,t,i;
       scanf("%d",&t);
       FOR(cs,1,t)
       {
              scanf("%d",&len);
              FOR(i,1,len) scanf("%d",&a[i]);
              a[0]=0;
              a[len+1]=INF;
              memo(vis,0);
              printf("Case %d: %d\n",cs,DP(0,len+1,1));
       }
}
