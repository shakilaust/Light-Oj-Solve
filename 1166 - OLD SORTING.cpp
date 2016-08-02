
//BISMILLAHIRRAHMANIRRAHIM
#include <stdio.h>

int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{  int a[110],count=0,t,j,k;
	   scanf("%d",&t);
	   for(j=1;j<=t;j++)
		   scanf("%d",&a[j]);
	 for(k=1;k<=t;k++)
		 if(a[k]!=k)
	 { for(j=k+1;j<=t;j++)
		 if(a[j]==k)
	 { int r=a[j];
	  a[j]=a[k];
	  a[k]=r;
	  count++;
	 }
	 }
	 printf("Case %d: %d\n",i,count);
	}
	return 0;
}
