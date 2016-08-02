
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
#include <deque>
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
	{   int a,b,c,count=0,abc[10];
	    cin>>a>>b;
	    deque <int> mydeque;
	    for(int j=1;j<=b;j++)
	    {  if(j==1)
		    printf("Case %d:\n",l);
	      char d[20];
	      scanf("%s",d);
	      getchar();
	     // if(j==5)
		     // printf("pop/push: %s\n",d);
	      if(d[1]=='u' && d[4]=='L'&& a>count)
	      { count++;
	        int t;
	        scanf("%d",&t);
	        mydeque.push_front(t);

	        printf("Pushed in left: %d\n",t);
	      }
	     else if(d[1]=='u' && d[4]=='R'&& count<a)
	      { count++;
	        int t;
	        scanf("%d",&t);
	        mydeque.push_back(t);

	        printf("Pushed in right: %d\n",t);
	      }
	     else if(d[1]=='o' && d[3]=='L'&& count>0)
	      {      // printf("Its Pop,j=%d count=%d\n",j,count);
		      --count;
	       int t=mydeque.front();
	       mydeque.pop_front();
	        printf("Popped from left: %d\n",t);

	      }
	      else if(d[1]=='o' && d[3]=='R'&& count>0)
	      {       //printf("Its Pop,j=%d count=%d\n",j,count);
		      --count;

	        int t=mydeque.back();
	       mydeque.pop_back();
	        printf("Popped from right: %d\n",t);

	      }

	     else if(d[1]='u' && count==a)
	     {       //printf("j=%d count=%d\n",j,count);
	             int t;
	             scanf("%d",&t);
		     printf("The queue is full\n");
	     }
	     else if(d[1]='0' && count==0)
	     { printf("The queue is empty\n");
	     }



	    }
	}

    return 0;
}
