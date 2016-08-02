
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#define pi cos(-1.0)
using namespace std;

double Extra(double x,double y,double z,double r)
{
    double  theta=acos((x*x+y*y-z*z)/(2.0*x*y));
    double area=(r*r*theta)/2.0;
    return area;
}
int main()
{
    int t,kase=1;
    for(scanf("%d",&t);kase<=t;kase++)
    {
        double R1,R2,R3;
        cin>>R1>>R2>>R3;
        double x=R1+R2;
        double y=R2+R3;
        double z=R3+R1;
        double s=(x+y+z)/2.0;
        double triangle=sqrt(s*(s-x)*(s-y)*(s-z));

        double extra=Extra(y,z,x,R3)+Extra(x,y,z,R2)+Extra(z,x,y,R1);
        printf("Case %d: %lf\n",kase,triangle-extra);
    }
}
