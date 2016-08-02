
#include <stdio.h>
int nim[105];
int main()
{   int t;
    scanf("%d",&t);
   for(int kase=1;kase<=t;kase++)
   {  int n,res,in;
	  scanf("%d",&n);
	  for(int i=0;i<n;i++)
		  scanf("%d",&nim[i]);
	 int count=0;
	  res=nim[0];
	  if(nim[0]>1) count++;
	 for(int i=1;i<n;i++)
	 {res^=nim[i];
	  if(nim[i]>1) count++;
	 }
	  if(count>=2)
	  {   if(!res) printf("Case %d: Bob\n",kase);
        else  printf("Case %d: Alice\n",kase);
	  }
	else
	{  if(!res) printf("Case %d: Alice\n",kase);
        else  printf("Case %d: Bob\n",kase);
	}
	}
 return 0;
}
