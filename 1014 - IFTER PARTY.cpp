
#include <vector>
#include<iostream>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string.h>
using namespace std;
vector <int> d;
void divisor(int n)
{
   int i=1,x,k=1;
	d.push_back(1);
	d.push_back(n);
   x=sqrt(n);
   if(n%2==0)
   {
   for(i=2;i<=x;i+=2)
	   if(n%i==0) { int res=n/i;
				   d.push_back(i);
				   d.push_back(res);
				   }
   }
   for(i=3;i<=x;i+=2)
	   if(n%i==0)
		   { int res=n/i;
				   d.push_back(i);
				   d.push_back(res);
		    }
}
int main()
{  int t;
   scanf("%d",&t);
   for(int kase=1;kase<=t;kase++)
   {  int p,l,dif;
	  d.clear();
	  bool ch=true;
	  scanf("%d %d",&p,&l);
	  dif=p-l;
	  divisor(dif);
	 sort(d.begin(),d.end());
	  printf("Case %d:",kase);
	  for(int i=0,sz=d.size();i<sz;i++)
		    if(d[i]>l)
				if(d[i]!=d[i-1])
			{printf(" %d",d[i]);
			  ch=false;
			}
	if(ch) printf(" impossible");
	printf("\n");
   }
 return 0;
}
