
//BISMILLAHIRRAHMANIRRAHIM

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
#define rep(i,n) for(int i = 0; i < n; i++)
#define re return
#define QI queue<int>
#define SI stack<int>
#define MAX 1000000
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))

using namespace std;

template<class T> T abs(T x) {re x > 0 ? x : -x;}
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }

int main()
{    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
	int n;
	cin>>n;
	for(int l=1;l<=n;l++)
	{  vector <int> arr;
	   int total,a,prev;
	   cin>>total;
	   cin>>a;
	   prev=a;
	   arr.pb(a);
	   int max=a;
	   for(int i=1,k;i<total;i++)
	   {  cin>>a;
	      k=(a-prev);
	      if(k>max)
		      max=k;
	      arr.pb(a);
	      prev=a;
	   }
	 int res=max,t=0;
	 if(arr[0]==max)
	 {max-=1;
	  t++;}
	 for(int i=1,sz=arr.size();i<sz;i++)
	 {   if(max<=abs(arr[i]-arr[i-1]))
		 max-=1;
	     if(res==arr[i]-arr[i-1])
		     t++;
	 }
	 if(max>0 && t<2)
	   printf("Case %d: %d\n",l,res);
	   else
	   {
	     printf("Case %d: %d\n",l,res+1);
	   }
	}

    return 0;
}
