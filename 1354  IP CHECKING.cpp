
#include <stdio.h>
#include <math.h>
bool check(int x,int y)
{  int sum=0,i=0;
   while(y>0)
{  int mod=y%10;
   sum+=mod*pow(2,i++);
   y/=10;
}
   if(x!=sum) return false;
   return true;
}
int main()
{
   int n,kase=1;
   scanf("%d",&n);
   while(n--)
   { int a,b,c,d,a1,b1,c1,d1;
     scanf("%d.%d.%d.%d",&a,&b,&c,&d);
     scanf("%d.%d.%d.%d",&a1,&b1,&c1,&d1);
     if( check(a,a1) && check(b,b1) && check(c,c1) && check(d,d1)) printf("Case %d: Yes\n",kase++);
     else printf("Case %d: No\n",kase++);
     }
     return 0;
    }

