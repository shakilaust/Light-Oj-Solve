
#include <stdio.h>
#include <string.h>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;
#define MAX 100005
set <int> res;
int total,n,val[MAX],coin[MAX],move[MAX];
bool money[MAX];

int main()
{     // freopen("input.txt","r",stdin);
       int cs,t,i,j,k;
       cin>>t;
       for(cs=1;cs<=t;cs++)
       {
              //res.clear();
              memset(money,0,sizeof(money));
              money[0]=1;
              scanf("%d %d",&n,&total);
              for(i=0;i<n;i++) cin>>coin[i];
              for(i=0;i<n;i++) cin>>val[i];
              int res=0;
              for(i=0;i<n;i++)
              {      for(k=0;k<=total;k++)
                     move[k]=0;
                     for(j=coin[i];j<=total;j++)
                     {
                            if(money[j-coin[i]] && !money[j] && move[j-coin[i]]<val[i])
                            {
                                   money[j]=1;
                                   move[j]=move[j-coin[i]]+1;
                                   res++;
                            }
                     }
              }
              printf("Case %d: %d\n",cs,res);

       }
}
