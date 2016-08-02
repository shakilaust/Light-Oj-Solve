
 //BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopner soman boro
 Author :: Shakil Ahmed
.............AUST_CSE27.........
 prob   ::
 Type   ::
 verdict::
 */
#include <bits/stdc++.h>

#define pf(a) printf("%d\n",a)
#define pf2(a,b) printf("%d %d\n",a,b)
#define pfcs(cs,a) printf("Case %d: %d\n",cs,a)
#define sc(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
#define pi acos(-1.0)
#define ff first
#define LL long long
#define ss second
#define rep(i,n) for(i = 0; i < n; i++)
#define REP(i,n) for(i=n;i>=0;i--)
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define ROF(i,a,b) for(int i = a; i >= b; i--)
#define re return
#define QI queue<int>
#define SI stack<int>
#define pii pair <int,int>
#define MAX
#define MOD
#define INF 1<<28
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define memo(a,b) memset((a),(b),sizeof(a))
#define G() getchar()
#define MAX3(a,b,c) max(a,max(b,c))

double const EPS=1e-10;
using namespace std;
double AB,AC,BC,ratio;
double solve()
{
        double s = ( AB + AC + BC ) / 2.0;

       double areaABC = sqrt(s*(s-AB)*(s-AC)*(s-BC));
       /* AB*BC  sin ( theata) = areaABC
        sin ( theata ) = areaABC / (AB * AC)
        ( theata ) = inverse sin ( areaABC / ( AB * BC ) )
        */
       double theata = asin( (areaABC) / (AB * BC));
       /* .05 * BC * H = areaABC
          H = ( 2 * areaABC / BC )
       */
       double H = ( ( 2 * areaABC ) / BC );
       /* areaADE = ratio * areaDEBC
          Again
          areaABC = areaADE + areaDEBC
          areaABC = ratio * areaDEBC + areaDEBC
          areaDEBC = areaABC / (ratio + 1)
          Again
          areaADE = ( areaABC - areaDEBC )

          */
       double areaDECB = ( areaABC / ( ratio + 1.0));
       double areaADE = areaABC - areaDECB ;

       double low = 0 , high = BC , DE , tmp = 0;

       while( fabs( H - tmp) > EPS )
       {
              DE = ( low + high ) / 2.0 ;
              tmp = ( ( 2 * areaADE ) / DE ) + ( 2 * areaDECB ) / ( BC + DE ) ;
              if ( tmp > H + EPS ) low= DE;
              else high = DE;
       }
       /*
        AD * DE * sin ( theata ) = areaADE
        AD = ( areaADE ) / ( DE * sin ( theata ) ) ; */
        double  AD = ( areaADE ) / ( DE * sin(theata) ) ;
     //   printf("Low::: %lf AD::%lf\n", ( areaADE) / ( low * sin(theata)),AD);
        return AD;

}
int main()
{
      int cs,t;
      scanf("%d",&t);
      for(cs=1;cs<=t;cs++)
      {
             cin>>AB>>AC>>BC>>ratio;
             printf("Case %d: %lf\n",cs,solve());

      }

      return 0;
}
