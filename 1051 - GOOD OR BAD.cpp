
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int dp[10][10][55],sz;
bool vis[10][10][55];
char str[60];
#define S(V) V[v][c][idx]
#define GOOD 0
#define BAD 1
#define MIXED 2
bool Isvouwel(char ch)
{
       if(ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U') return 1;
       else return 0;
}
int DP(int v,int c,int idx)
{
       if(v>=3 || c>= 5) return BAD;
       if(idx>= sz) return GOOD;
       if(S(vis)) return S(dp);
       S(vis)=1;
       if(str[idx]=='?')
       {
              int a=DP(v+1,0,idx+1);
              int b=DP(0,c+1,idx+1);
              if(a==GOOD && b==GOOD) S(dp)=GOOD;
              else  if(a==BAD && b==BAD) S(dp)=BAD;
              else S(dp)=MIXED;

       }
       else if(Isvouwel(str[idx])) S(dp)=DP(v+1,0,idx+1);
       else S(dp)=DP(0,c+1,idx+1);
       return S(dp);
}
int main()
{
       int cs,t;
       scanf("%d",&t);
       for(cs=1;cs<=t;++cs)
       {
                scanf("%s",str);
                sz=strlen(str);
                memset(vis,0,sizeof(vis));
                int ans=DP(0,0,0);
                if(!ans) printf("Case %d: GOOD\n",cs);
                else if(ans==2) printf("Case %d: MIXED\n",cs);
                else printf("Case %d: BAD\n",cs);


       }
}
