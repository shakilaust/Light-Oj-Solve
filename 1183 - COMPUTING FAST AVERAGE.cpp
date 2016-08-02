
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

const int N = 100005;

LL sum[3*N] , Lazy[3*N] ,  Maxval ;
void LazYPropagrate(int idx,int left,int right)
{      if(left!=right) {
       Lazy[2*idx] = Lazy[idx];
       Lazy[2*idx+1] = Lazy[idx];
          }
       sum[idx] = Lazy[idx]*((right-left)+1);
       Lazy[idx] = -1;
}
void ini(int node , int left , int right )
{
       Lazy[node] = -1 ;
       sum [ node] = 0;
       if(left == right ) return ;
       int mid = ( right + left) /2 ;
       ini(2*node,left,mid);
       ini(2*node+1,mid+1,right);

}
void update(int node,int left,int right,int x,int y,LL val)
{
       if(Lazy[node]!=-1) LazYPropagrate(node,left,right);
       if(left>y || right < x) return ;
       if( x<=left && right<=y )
       {

              sum[node] = val*((right-left)+1);
              if(left!=right)
              {
                     Lazy[2*node] = val;
                     Lazy[2*node+1] = val;
              }
              return ;
       }
       int mid =(right + left ) /2;
       update(2*node,left,mid,x,y,val);
       update(2*node+1,mid+1,right,x,y,val);
       sum[node] = sum[2*node]+ sum[2*node+1];
}
LL query(int node,int left,int right,int x,int y)
{
       if(Lazy[node]!=-1) LazYPropagrate(node,left,right);
       if(left>y || x>right || left>right) return 0;
       if(x<=left && y>=right )
       {

              return sum[node];
       }
       int mid = (left + right ) /2 ;
       LL res = 0;
       res = query(2*node,left,mid,x,y) + query(2*node+1,mid+1,right,x,y);
       //sum[node] = sum[2*node]+ sum[2*node+1];
       return res;
}
int main()
{
       int cs, t ;
       scanf("%d",&t);
       for ( cs = 1 ; cs <= t ; cs++ )
       {
              int n, q, i , op, x, y;
              scanf("%d %d",&n,&q);
              printf("Case %d:\n",cs);
              ini(1,0,n-1);
              for ( i = 0 ; i < q; i++ )
              {
                     scanf("%d",&op);
                     if(op==2)
                     {
                            scanf("%d %d",&x,&y);
                            LL ans=query(1,0,n-1,x,y);
                             LL between = ( y - x) +1;
                           // printf("ans ::: %lld between :: %lld\n",ans, between);

                            if(ans % between == 0 ) printf("%lld\n",ans/between);
                            else
                            {
                                   LL div = gcd(ans,between);
                                   printf("%lld/%lld\n",ans/div,between/div);
                            }
                     }
                     else
                     {      LL val ;
                            scanf("%d %d %lld",&x,&y,&val);
                            update(1,0,n-1,x,y,val);
                     }
              }
       }
}
