

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
}p[10];
double dis(point A, point B)
{
    return ( (A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y));
}
double ternary()
{
    int i ;
    point first , second ;
    first.x = p[1].x-p[0].x;
    first.y= p[1].y - p[0].y;
    second.x = p[3].x - p[2].x;
    second.y = p[3].y-p[2].y;
    double high=1.0, low = 0 , midLeft , midRight ;
    double res = 1e18;
    for ( i = 0 ; i <200; i++ )
    {
        midLeft = ( 2*low + high) / 3.0;
        midRight = ( low + 2*high) / 3.0;
        point A,B;
        A.x = p[0].x + first.x*midLeft;
        A.y = p[0].y + first.y*midLeft;
        B.x =p[2].x + second.x*midLeft;
        B.y = p[2].y + second.y*midLeft;
        double d1=dis(A,B);
        A.x = p[0].x + first.x*midRight;
        A.y = p[0].y + first.y*midRight;
        B.x =p[2].x + second.x*midRight;
        B.y = p[2].y + second.y*midRight;
        double d2=dis(A,B);
        if(d1>d2) low = midLeft;
        else high = midRight;
        res = min(res,min(d1,d2));
    }
    return sqrt(res);
}
int main()
{
       // freopen("input.txt","r",stdin);
       int cs  , t ;
       cin >> t ;
       for ( cs = 1 ; cs <= t ; cs++ )
       {
           cin>>p[0].x>>p[0].y>>p[1].x>>p[1].y>>p[2].x>>p[2].y>>p[3].x>>p[3].y;
           printf("Case %d: %lf\n",cs,ternary());

       }
       return 0;

}
