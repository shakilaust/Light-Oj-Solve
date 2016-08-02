
#include <stdio.h>
int main()
{  int t;
   scanf("%d",&t);
   for(int kase=1;kase<=t;kase++)
   { int res=0,arr[205],a,b,n;
	  scanf("%lld",&n);
	  int i=0;
	  while(n--)
	  {  scanf("%d %d",&a,&b);
	    arr[i++]=(b-a-1);
	  }
	for(int j=0;j<i;j++) res^=arr[j];
	if(!res) printf("Case %d: Bob\n",kase);
	else printf("Case %d: Alice\n",kase);
   }
 return 0;
}
