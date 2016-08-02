
#include <stdio.h>
#include <math.h>
int white[105],black[105];
int main()
{  int t;
   scanf("%d",&t);
   for(int kase=1;kase<=t;kase++)
   {  int n;
      scanf("%d",&n);
      for(int i=0;i<n;i++)
          scanf("%d",&white[i]);
      for(int i=0;i<n;i++)
          scanf("%d",&black[i]);
	  int  res=abs(white[0]-black[0])-1;
      for(int i=1;i<n;i++)
      {   int r=abs(white[i]-black[i])-1;
	      res^=r;
      }
      if(!res) printf("Case %d: black wins\n",kase);
	  else printf("Case %d: white wins\n",kase);
   }
 return 0;
}
