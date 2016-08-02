
#include <stdio.h>
#include <algorithm>
using namespace std;
double W,L;
double cal(double a,double b,double x)
{
    return (a-2*x)*(b-2*x)*x;
}
void solve()
{   int iter;
    double l=0,r=min(W,L)*.5,mid1,mid2;
    for(iter=1;iter<=200;iter++)
    {
        mid1=l+(r-l)/3;
        mid2=l+(r-l)/3*2;
        double f1=cal(W,L,mid1);
        double f2=cal(W,L,mid2);
        if(f1>f2)
        {
            r=mid2;
        }
        else
        l=mid1;
    }
    printf("%.10f\n", cal(W,L,r));
}
int main()
{
    int t,cs;
    scanf("%d",&t);
    for(cs=1;cs<=t;cs++)
    {   scanf("%lf %lf",&W,&L);
        printf("Case %d: ",cs);
        solve();
    }
}
