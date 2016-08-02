
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <sstream>

using namespace std;

int cases, caseno, n;

int main() {

	scanf("%d", &cases);
	while( cases-- ) {
		int s = 0;
		scanf("%d", &n);
		while( n-- ) {
			int k;
			scanf("%d", &k);
			if( k > 0 ) s += k;
		}
		printf("Case %d: %d\n", ++caseno, s);
	}
	return 0;
}
