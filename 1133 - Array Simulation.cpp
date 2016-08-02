
//BISMILLAHIRRAHMANIRRAHIM
//
//

#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <vector>
#include <stack>
#include <string>
#include <list>
#include <map>
#include <queue>
#include <sstream>
#include <utility>
#define pb push_back
#define mp make_pair
#define pi acos(-1.0)
#define LL long long
#define ff first
#define ss second
#define QI queue<int>
#define SI stack<int>
#define MAX 1000000
using namespace std;
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
int main()
{    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
	int n;
	cin>>n;
	for(int l=1;l<=n;l++)
	{  int a,b,array[105],array1[105],j,i;
	   scanf("%d %d",&a,&b);
	   getchar();
	   for(i=0;i<a;i++)
		   scanf("%d",&array[i]);
	           getchar();
	  // for(i=0;i<a;i++)
		 //  printf("%d: %d\n",i,array[i]);
	 for(i=0;i<b;i++)
	 {	 char c,ar[20];
	         int d,e;
	     gets(ar);
	  //printf("%s\n",ar);
	   sscanf(ar,"%c %d %d",&c,&d,&e);
	 // printf("c: %c\td :%d\te: %d\n",c,d,e);
	    if(c=='S')
	    {
		    for(j=0;j<a;j++)
			    array[j]+=d;
	    }
	 else if(c=='M')
	 {     for(j=0;j<a;j++)
			    array[j]*=d;
	 }
	 else if(c=='D')
	 {     for(j=0;j<a;j++)
			    array[j]/=d;
	 }
	 else if (c=='P')
	 {  int u=array[d];
	  array[d]=array[e];
	  array[e]=u;
	 }
	 else
	 {       int t=0;
		 for(j=a-1;j>-1;j--)
		 {array1[t++]=array[j];
		  //printf("%d: %d\t%d: %d\n",j,array[j],t-1,array1[t-1]);
		 }
	         for(j=0;j<t;j++)
			 array[j]=array1[j];
	 }

	}
	 printf("Case %d:\n",l);
	 for(j=0;j<a;j++)
	 {printf("%d",array[j]);
	  if(j!=a-1)
		  printf(" ");
	  else
		  printf("\n");
	 }
	}

    return 0;
}
