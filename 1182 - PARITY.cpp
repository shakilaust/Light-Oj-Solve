
#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	#ifndef LIGHTOJ
		freopen("a.in", "r", stdin);
	#endif
        int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int num,val=0;;
		cin>>num;
		while(num>0)
		{
                   if( num%2==1)
			   val++;
			num/=2;
		}
		if(val%2==0)
			printf("Case %d: even\n",i);
		else
			printf("Case %d: odd\n",i);
	}
	return 0;
}
