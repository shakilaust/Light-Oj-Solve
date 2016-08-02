
#include <algorithm>
#include <stdio.h>
#include <iostream>
#define MAX_N 100005
#define mod  1000007
#define FOR(i,j,k) for(i=j;i<=k;i++)
using namespace std;
long long int a[MAX_N];
int main()
{
       int t,cs;
       cin>>t;
       FOR(cs,1,t)
       {
              int K,C,N,i;
              long long int sum=0,ans=0;
              cin>>K>>C>>N>>a[0];
              FOR(i,1,N-1)
              a[i]=(K*a[i-1]+C)%mod;
              sort(a,a+N);
              FOR(i,1,N-1)
              {
                     sum+=a[i-1];
                     ans+=(a[i]*i)-sum;
              }
            printf("Case %d: %lld\n",cs,ans);


       }
}
