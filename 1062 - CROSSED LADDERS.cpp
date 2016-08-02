
 //BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopner soman boro
 Author :: Shakil Ahmed
.............AUST_CSE27.........
 prob   ::
 Type   ::
 verdict::
 */

#include <stdio.h>
#include <math.h>
#define min(a,b) ( (a) < (b) ? (a) : (b) )
/* **************************************  My code start here ****************************************** */
double x , y , c ;
const double EPS = 1e-8;
double call(double mid)
{
    double h = 1.0/sqrt(x*x-mid*mid) + 1.0/sqrt(y*y-mid*mid);
    return h ;
}
int main()
{
    int cs , t ;
    scanf("%d",&t);
    for ( cs = 1 ; cs <= t ; cs++ )
    {
        scanf("%lf %lf %lf",&x,&y,&c);
        double low = 0.0 , high = min(x,y) , mid ;
        double end = 1.0/c;
        while(EPS<=(high-low))
        {
            mid = (low+ high)/2.0;
            if(call(mid) < end ) low = mid ;
            else high =  mid ;
        }
        printf("Case %d: %lf\n",cs,mid);
    }
   return 0;
}
