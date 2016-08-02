
//BISMILLAHIRRAHMANIRRAHIM
/* Author :Shakil_AUST
   problem: Light Oj 1241
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
#define ROF(i,a,b) for(int i = a; i <= b; i++)
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

int main()
{    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
	int n;
	cin>>n;
	rep(i,n)
	{ int arr[55],Lie=0,num;
	  arr[0]=2;
	  cin>>num;
	  rep(j,num) cin>>arr[j+1];
	  for(int indx=1;indx<=num;indx++)
	  if(arr[indx]>arr[indx-1]) Lie+=ceil((double)((arr[indx]-arr[indx-1]))/5);

	  printf("Case %d: %d\n",i+1,Lie);
	}

    return 0;
}
