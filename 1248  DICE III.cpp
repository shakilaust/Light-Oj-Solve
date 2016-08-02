
#include <stdio.h>
#define MAX 100005
int cs;
double ans[MAX];

void solve()
{
    int i;
    ans[1]=1.0;
    for(i=2;i<=MAX-5;i++) ans[i]=(ans[i-1]+(1.0/i)); // 1 er junno all expected value ber kore rakhlam

}
int main()
{  int t;
   solve();
   scanf("%d",&t);
   for(cs=1;cs<=t;cs++)
   {
       int n;
       scanf("%d",&n);
       printf("Case %d: %lf\n",cs,n*ans[n]); // ami ekhane agei 1 er junno sob ber kore rakhchi ekhane oikik niyom chalaitechi
         //   like 10000 er junno hoile 100kisu
         // 1 er junno 100/10000
          // taile ekhon n er junno ki hobe n*100/10000 emoni to kisu
   }

}
