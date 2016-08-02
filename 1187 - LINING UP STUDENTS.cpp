
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
const int MAXN = 100005;

int tree[MAXN] , ans[MAXN] , inp[MAXN] , maxVal , n;

void write(int idx,int val)
{
       while(idx <= n )
       {
              tree[idx] += val;
             // printf("val::%d\n",val);
              idx += (idx & -idx);
       }
}
int read(int idx)
{
       int sum = 0 ;
       while(idx > 0 )
       {
              sum += tree[idx] ;
              idx -= ( idx & -idx);
       }
      // printf("sum :: %d\n",sum);
       return sum;
}
int solve()
{
       int i , left , right , tmp , mid ;
       maxVal = n ;
       for ( i = n ; i>=1 ; i-- )
       {
              tmp = i - inp[i];
             // printf("tmp:: %d\n",tmp);
              right = n ;
              left = 1;
              while(left <= right )
              {
                     mid = ( left + right ) / 2 ;
                   //  printf("mid::%d read()::%d\n",mid,read(mid));
                     if( read( mid )>= tmp )
                     {
                            right = mid - 1;
                     }
                     else left = mid + 1;
                   //  printf("left %d right :: %d\n",left,right);
              }
               write(left,-1);
              ans[i] = left;

       }

       return ans[1];
}
int main()
{
    int cs , t ,i;
    scanf("%d",&t);
    for ( cs = 1 ; cs <= t ; cs++ )
    {      scanf("%d",&n);
           memo(tree,0);
           for(i=1 ; i <= n ; i++ )
           {
                  scanf("%d",&inp[i]);
                  write(i,1);
                  ans[i] = 0;


           }
           tree[0] = 0;
           printf("Case %d: %d\n",cs,solve());
    }
}
