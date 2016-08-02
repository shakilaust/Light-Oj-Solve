
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
const int N = 1005;
struct point
{
    int x , y ;
};
point p[N];
point inp[N*N];
int n;
bool cmp(point A , point B)
{
    if(A.x == B.x ) return A.y < B.y;
    return A.x < B.x;
}
int main()
{
       // freopen("input.txt","r",stdin);
       int cs , t , i , j , k;
       scanf("%d",&t);
       for ( cs = 1 ; cs <= t ; cs++ )
       {
           scanf("%d",&n);
           for ( i = 0 ; i < n ; i++ )
           {
               scanf("%d %d",&p[i].x,&p[i].y);
           }
           for ( i = k = 0 ; i < n ;i++)
           {
               for ( j = i + 1 ; j < n ; j++ )
               {
                   inp[k].x = p[i].x+p[j].x;
                   inp[k++].y = p[i].y + p[j].y;
               }
           }
           sort(inp,inp+k,cmp);
           int ans = 0 , cnt = 1;
           for(i=1;i<k;i++)
           {

               if(inp[i].x!=inp[i-1].x || inp[i].y!=inp[i-1].y)
               {
                   ans += (cnt*(cnt-1))/2;
                   cnt = 1;
               }
               else
               {
                   cnt +=1;
               }
           }
           printf("Case %d: %d\n",cs,ans);
       }
       return 0;

}
