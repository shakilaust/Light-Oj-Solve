#include <stdio.h>
#include <algorithm>
using namespace std;
#define INF -10000
int main()
{  int t,kase;
   scanf("%d",&t);
   getchar();
   for(kase=1;kase<=t;kase++)
   {  int n,i,j,k;
	  scanf("%d",&n);
	  int arr[2*n+5][2*n+5];
	 for(i=0;i<=2*n;i++) arr[0][i]=0;
	for(i=1;i<=2*n;i++)
		for(j=0;j<=2*n;j++) arr[i][j]=INF;
	 for(i=1;i<=n;i++)
		 for(j=1;j<=i;j++)
			  scanf("%d",&arr[i][j]);
	for(k=n-1;i<=2*n-1;k--,i++)
		 for(j=1;j<=k;j++)
			  scanf("%d",&arr[i][j]);
		 for(i=1;i<=n;i++)
			 for(j=1;j<=i;j++)
				  if(j==1)
					 arr[i][j]=arr[i][j]+arr[i-1][j];
				 else if(j==n)
					 arr[i][j]=arr[i][j]+arr[i-1][j-1];
				 else
				      arr[i][j]=arr[i][j]+max(arr[i-1][j-1],arr[i-1][j]);

		for(k=n-1;i<=2*n-1;i++,k--)
			for(j=1;j<=k;j++)
				 arr[i][j]=arr[i][j]+max(arr[i-1][j],arr[i-1][j+1]);

			 printf("Case %d: %d\n",kase,arr[2*n-1][1]);
   }
 return 0;
}
