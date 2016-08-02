
#include<stdio.h>
#include<math.h>
#define maxnum 1000000
#define len 1000010
double logfactor[len]={0};
void ini()
{     int i;
      for (i=1;i<=maxnum;i++)
        logfactor[i]=logfactor[i-1]+log10(i);
    logfactor[0]=0.1;
}
int main()
{
    int T,Ts,n,m,i;
    ini();
    scanf("%d",&T);
    for (Ts=1;Ts<=T;Ts++)
    {
        scanf("%d%d",&n,&m);
        printf("Case %d: %.0lf\n",Ts,ceil(logfactor[n]/log10(m)));
    }
    return 0;
}
