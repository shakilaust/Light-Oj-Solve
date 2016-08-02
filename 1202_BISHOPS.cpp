
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
	for(int i=1;i<=n;i++)
	{
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		if(((a+b)%2==1 && (c+d)%2!=1) || ((a+b)%2!=1 && (c+d)%2==1))
			printf("Case %d: impossible\n",i);
		else if((a==c && b==d))
			printf("Case %d: 0\n",i);
		else if(abs(a-c)==abs(b-d))
			printf("Case %d: 1\n",i);
		else
			printf("Case %d: 2\n",i);
	}


    return 0;
}
