
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
const int SZ = 1005;
int tree[SZ][SZ];
bool vis[SZ][SZ];

void write(int r,int c,int val)
{
       int x, y ;
       for ( x = r ; x <= SZ ; x += ( x & -x))
       {
              for ( y = c ; y <= SZ ; y += ( y & -y)) tree[x][y] += val;
       }
}
int read(int r,int c)
{
       int x, y , sum = 0 ;
       for ( x = r ; x > 0 ; x -= ( x & -x))
       {
              for( y = c ; y > 0 ; y -= ( y & -y))
              {
                     sum += tree[x][y];
              }
       }
       return sum;
}

int main()
{
    int cs, t , r1, c1, r2 , c2 , op , q, i;
    scanf("%d",&t);
    for ( cs = 1 ; cs <= t ; cs++ )
    {
           memo(tree,0);
           memo(vis,0);
           scanf("%d",&q);
           printf("Case %d:\n",cs);
           for ( i = 0 ; i < q ; i++ )
           {
                  scanf("%d",&op);
                  if(!op)
                  {
                         scanf("%d %d",&r1,&c1);
                         r1 +=1;
                         c1 += 1;
                         if(!vis[r1][c1])
                         write(r1,c1,1);
                         vis[r1][c1] = 1;
                  }
                  else
                  {
                         scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
                         r1 += 1; // x1
                         c1 += 1; // y1
                         r2 += 1; // x2
                         c2 += 1; // y2
                         int ans = read(r2,c2); // x2,y2
                         ans -= read(r1-1,c2); // x1 , y2
                         ans -= read(r2,c1-1) ; // x2,y1
                         ans += read(r1-1,c1-1); // x1,y1
                         printf("%d\n",ans);

                  }
           }

    }
}
