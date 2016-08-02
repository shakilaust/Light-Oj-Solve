
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
		int row,col,moves,test_case;
	  cin>>test_case;
	for(int i=1;i<=test_case;i++)
	{



scanf("%d %d",&row,&col);
if(row==1 || col==1)
moves=max(row,col);
else if(row==2 || col==2)
moves = (min((max(row,col) % 4), 2)) * 2 + (max(row,col)/4) * 4;
else
moves=(row*col+1)/2;
printf("Case %d: %d\n",i,moves);
        }


	return 0;
}
