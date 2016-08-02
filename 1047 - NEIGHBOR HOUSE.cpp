
#include <stdio.h>
#include <algorithm>
using namespace std;
int in[22][3];
int main()
{
    int test,kase=1;
    for(scanf("%d",&test);kase<=test;kase++)
    {
     int n;
     scanf("%d",&n);
     for(int i=0;i<n;i++) scanf("%d %d %d",&in[i][0],&in[i][1],&in[i][2]);
     for(int i=n-2;i>-1;i--)
      {
       for(int j=0;j<3;j++)
         in[i][j]+=min(in[i+1][(j+1)%3],in[i+1][(j+2)%3]);
      // printf("%d:  %d   %d   %d\n",i,in[i][0],in[i][1],in[i][2]);
      }
     printf("Case %d: %d\n",kase,min(in[0][0],min(in[0][1],in[0][2])));
    }
    return 0;
}
