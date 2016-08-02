
//BISMILLAHIRRAHMANIRRAHIM
/* Author :Shakil_AUST
   problem:
   Type   :
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
using namespace std;
#define MAX 1000005
int arr[MAX];
int main()
{  int t,kase;
   scanf("%d",&t);
   for(kase=1;kase<=t;kase++)
   {  int n,a,i,sz;
	  long long int total=0;
	  memset(arr,0,sizeof(arr));
	  vector <int> v;
	  scanf("%d",&n);
	  while(n--)
	  { scanf("%d",&a);
	    if(arr[a]==0) total+=a+1;
	    arr[a]+=1;
	    if(arr[a]==a+1) arr[a]=0;
	  }

	printf("Case %d: %lld\n",kase,total);

   }
 return 0;
}
