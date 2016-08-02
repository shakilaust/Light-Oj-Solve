
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<iostream>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<algorithm>
using namespace std;
#define sq(a) a*a
#define size 100
#define  PIx 2 * acos (0.0)


int main()
{

    long long n,m,t,i;
    long long s,p,q,av,k;



    scanf("%lld",&t);

    for(i=0; i<t; i++)
    {

        scanf("%lld %lld",&n,&m);

        k=n/m-1;

        av=ceil(k/2.0);

        p=(av*av);

        av=floor(k/2.0);

        q=(av)*((2+k-1)/2);

        s=(p-q)*m*m;

        printf("Case %lld: %lld\n",i+1,s);
    }
    return 0;
}
