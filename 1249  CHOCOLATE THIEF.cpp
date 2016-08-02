
//BISMILLAHIRRAHMANIRRAHIM
/* Author :Shakil_AUST
   problem: Light Oj
   Type   : Adhoc
*/

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
#define REP(i,n) for(int i=n;i>=0;i--)
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define rof(i,a,b) for(int i = a; i >= b; i--)
#define re return
#define QI queue<int>
#define SI stack<int>
#define pii pair <int,int>
#define MAX 1000000
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))

using namespace std;

template<class T> T abs(T x) {re x > 0 ? x : -x;}
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
struct abc
{  char str[30];
   int val;
}input[105];
bool comp ( abc aa,abc bb)
{  if(aa.val>bb.val) return true;
   else false;
}
int main()
{    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
	int n;
	cin>>n;
	rep(i,n)
	{  int test,a,b,c;
	  char name[30];
	  cin>>test;
	 rep(j,test) { scanf("%s %d %d %d",input[j].str,&a,&b,&c) ; input[j].val=a*b*c;}
	  if(input[0].val<input[test-1].val) {
			  strcpy(name,input[test-1].str);
		          strcpy(input[test-1].str,input[0].str);
		          strcpy(input[0].str,name);
			  swap(input[0].val,input[test-1].val);
			 }
	 FOR(j,1,test-2) {if(input[0].val<input[j].val) {
		          strcpy(name,input[0].str);
		          strcpy(input[0].str,input[j].str);
		          strcpy(input[j].str,name);
			  swap(input[0].val,input[j].val);}
			  if(input[j].val<input[test-1].val) {
			  strcpy(name,input[test-1].str);
		          strcpy(input[test-1].str,input[j].str);
		          strcpy(input[j].str,name);
			  swap(input[j].val,input[test-1].val);}
			 }
	  if(input[0].val==input[test-1].val) printf("Case %d: no thief\n",i+1);
	  else printf("Case %d: %s took chocolate from %s\n",i+1,input[0].str,input[test-1].str);
	}

    return 0;
}
