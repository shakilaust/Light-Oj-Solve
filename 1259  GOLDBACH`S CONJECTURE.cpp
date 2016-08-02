
#include <stdio.h>
#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;
#define MAX 10000000+5
vector <int> prime;
bool check[MAX+10];
int main()
{
    int i,j,k=1,kase,t,n;
    check[0]=check[1]=1;
    check[2]=0;
    prime.push_back(2);
    for(i=4;i<MAX;i+=2)
    check[i]=1;
    for(i=3; i*i<MAX; i+=2)
    {
        if(check[i]) continue;
        for(j=3; j*i<MAX; j+=2) check[i*j]=1;
    }
    for(i=3;i<MAX;i+=2)
      if(!check[i])
      prime.push_back(i);
    scanf("%d",&t);
    for(kase=1; kase<=t; kase++)
    {
        int count=0;
        scanf("%d",&n);
        for(i=0; prime[i]<=n/2; i++)
        {
            if(!check[n-prime[i]])
            {
                count++;

            }

        }
        printf("Case %d: %d\n",kase,count);

    }
}
