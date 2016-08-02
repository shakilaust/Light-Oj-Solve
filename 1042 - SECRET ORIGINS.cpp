
#include <stdio.h>
typedef unsigned int uint_t;

// this function returns next higher number with same number of set bits as x.
int snoob(int x)
{

  int rightOne;
  int nextHigherOneBit;
  int rightOnesPattern;

  int next = 0;

  if(x)
  {

    // right most set bit
    rightOne = x & -(signed)x;

    // reset the pattern and set next higher bit
    // left part of x will be here
    nextHigherOneBit = x + rightOne;

    // nextHigherOneBit is now part [D] of the above explanation.

    // isolate the pattern
    rightOnesPattern = x ^ nextHigherOneBit;

    // right adjust pattern
    rightOnesPattern = (rightOnesPattern)/rightOne;

    // correction factor
    rightOnesPattern >>= 2;

    // rightOnesPattern is now part [A] of the above explanation.

    // integrate new pattern (Add [D] and [A])
    next = nextHigherOneBit | rightOnesPattern;
  }

  return next;
}
int main()
{    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
        int test;
        scanf("%d",&test);
        for(int kase=1;kase<=test;kase++)
        {  int N;
           scanf("%d",&N);
           N=snoob(N);
          printf("Case %d: %d\n",kase,N);
        }


    return 0;
}
