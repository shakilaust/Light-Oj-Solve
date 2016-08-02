

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
    LL x , y;
};
vector < point > P;
LL area(point A,point B)
{
    return A.x*B.y-A.y*B.x;
}
LL PolyArea()
{
    int sz = P.size();
    LL res=area(P[sz-1],P[0]);
    int i;
    for ( i = 0; i < sz-1 ; i++ )
    {
        res += area(P[i],P[i+1]);
    }
    return fabs(res)*.5;
}
LL getboard()
{  int sz=P.size(), i ;
    LL res=gcd(abs(P[0].x-P[sz-1].x),abs(P[0].y-P[sz-1].y));
    for ( i = 0; i < sz-1 ; i++ )
    {
        res += gcd(abs(P[i].x-P[i+1].x),abs(P[i].y-P[i+1].y));
    }
    return res;
}
int main()
{
       // freopen("input.txt","r",stdin);
       int cs , t ;
       scanf("%d",&t);
       for ( cs = 1 ; cs <= t ; cs++)
       {
           P.clear();
           point inp;
           int n , i;
           cin>>n;
           for(i=0;i<n;i++)
           {
               cin>>inp.x>>inp.y;
               P.pb(inp);
           }
           /* here
           A = area of polygoanal
           B = boundoury points of polygonal
           I = inside points of polygonal
           */
           LL A=PolyArea();
           LL B=getboard();
           LL I= A + 1 - B/2;
           printf("Case %d: %lld\n",cs,I);

       }
       return 0;

}
