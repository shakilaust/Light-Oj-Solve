
#include <stdio.h>
#include <string.h>
int a[100];
int main()
{
       int cs,t;
       scanf("%d",&t);
       for(cs=1;cs<=t;cs++)
       {
              int i,j,r,c,res=0;
              scanf("%d %d",&r,&c);
              //memset(a,0,sizeof(a));
              for(i=0;i<r;i++)
              {
                     int in,sum=0;
                     for(j=0;j<c;j++)
                     {
                            scanf("%d",&in);
                            sum+=in;
                     }
                     res^=sum;
              }
            if(res) printf("Case %d: Alice\n",cs);
            else printf("Case %d: Bob\n",cs);
       }
}
