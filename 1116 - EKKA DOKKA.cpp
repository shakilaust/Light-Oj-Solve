
//BISMILLAHIRRAHMANIRRAHIM
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
	int n;
	cin>>n;
	for(int l=1;l<=n;l++)
	{  long long int a,i,j;
	   cin>>a;
	   if(a%2==1)
		   printf("Case %d: Impossible\n",l);
	   else
	   {        int w=0;
		   for(i=2;i<=a/2;i*=2)
			if((a/i)%2==1)
	   { printf("Case %d: %lld %lld\n",l,a/i,i);
	     w=1;
	    break;
	   }
	    if(w==0)
		    printf("Case %d: 1 %lld\n",l,a);

	   }
	}

    return 0;
}
