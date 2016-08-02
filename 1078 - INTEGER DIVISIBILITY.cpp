
#include <stdio.h>
int main()
{
       int cs,t;
       scanf("%d",&t);
       for(cs=1;cs<=t;cs++)
       {
              int n,m,sum=0,ct=1;
              scanf("%d %d",&n,&m);
              while(((sum*10)+m)%n)
              {
                     sum=((sum*10)+m)%n;
                     ct++;
              }
              printf("Case %d: %d\n",cs,ct);
       }
}
