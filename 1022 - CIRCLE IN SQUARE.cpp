
#include <stdio.h>
#include <math.h>

const double pi = 2 * acos(0.0);

int main() {


	int cases, caseno = 0;
	double rad, l;

	scanf("%d", &cases);
	while( cases-- ) {
		scanf("%lf", &rad);
		l = 2 * rad;
		l = l * l - pi * rad * rad;
		printf("Case %d: %.2lf\n", ++caseno, l + 1e-11);
	}
	return 0;
}
