

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
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>
#include <set>
#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <list>
#include <map>
#include <queue>
#include <sstream>
#include <utility>
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
#define INF 1<<30
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define memo(a,b) memset((a),(b),sizeof(a))
#define G() getchar()
#define MAX3(a,b,c) max(a,max(b,c))

double const EPS=3e-8;
using namespace std;


template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
struct point
{
    double x , y ;
};
double Dis(point O , point A)
{
    return sqrt(( O.x - A.x)*(O.x-A.x) + (O.y-A.y)*(O.y-A.y));
}
int main()
{
       // freopen("input.txt","r",stdin);
       int cs, t ;
       cin >> t ;
       for ( cs = 1 ; cs <= t ; cs++ )
       {
           point A , B , O;
           cin >> O.x >> O.y >> A.x >> A.y >> B.x >> B.y;
           double r =Dis(O,A);
           double OA = Dis (O,A);
           double OB = Dis(O,B);
           double AB= Dis(A,B);
           double angle = acos ( (OA*OA+OB*OB-AB*AB)/(2*OA*OB));
           double ans = r * angle;
           printf("Case %d: %lf\n",cs,ans);
       }
       return 0;

}
