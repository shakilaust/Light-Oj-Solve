
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
const int N = 4 * 100000 + 5 ;

LL tree[N][3] , Lazy[N] ;

void LazYPropagrate (int node,int left ,int right)
{      if(left!=right)
       {
              Lazy[2*node] = ( Lazy[node] + Lazy[2*node])%3;  // updating lazy value
              Lazy[2*node+1] = ( Lazy[node] + Lazy[2*node+1])%3;
       }
       if(Lazy[node] == 1)
       {
              tree[node][2] = tree[node][1];
              tree[node][1] = tree[node][0];
              tree[node][0] = ( right - left ) + 1 - tree[node][1] - tree[node][2];
       }
       if(Lazy[node] == 2 )
       {
              tree[node][1] = tree[node][2];
              tree[node][2] = tree[node][0];
              tree[node][0] = ( right - left ) + 1 - tree[node][1] - tree[node][2];
       }
       Lazy[node] = 0;
}

void ini(int node , int left , int right )
{
       tree[node][0] = ( right - left ) + 1;
       tree[node][1] = 0 ;
       tree[node][2] = 0 ;
       Lazy[node] = 0;
       if(left == right )
       {
              tree[node][0] = 1;
              return ;
       }
       int mid = ( right + left ) / 2;
       ini(2*node,left,mid);
       ini(2*node+1,mid+1,right);

}
void update(int node,int left ,int right ,int a, int b)
{      if(Lazy[node]) LazYPropagrate(node,left,right);
       if( a > right || b < left ) return ;
        if( a <= left && b>= right )
        {
               if(left!=right )
               {
                      Lazy[2*node] = ( Lazy[2*node]+1)%3; // updating Lazy value
                      Lazy[2*node+1]= ( Lazy[2*node+1] + 1 ) % 3;
               }
               tree[node][2] = tree[node][1];
               tree[node][1] = tree[node][0];
               tree[node][0] = ( right - left ) + 1 - tree[node][1] - tree[node][2];
               return ;
        }
       int mid = ( right + left ) / 2;
       update(2*node,left,mid,a,b);
       update(2*node+1,mid+1,right,a,b);
       int k = 0 ;
       for ( k = 0 ; k <3 ;k++) tree[node][k] = tree[2*node][k] + tree[2*node+1][k];
}
LL query(int node,int left , int right ,int a, int b)
{      if(Lazy[node]) LazYPropagrate(node,left,right);
       if( a > right || b < left ) return 0;
       if( a<= left && b>=right ) return tree[node][0];
       int mid = (right + left )/ 2;
       LL res1 = query(2*node,left,mid,a,b);
       LL res2 = query(2*node+1,mid+1,right,a,b);
       int k ;
       for ( k = 0 ; k < 3 ; k++ ) tree[node][k] = tree[2*node][k] + tree[2*node+1][k];
       return res1+res2;
}
int main()
{
   int n , q , op , x, y, i;
   int cs,t;
   scanf("%d",&t);
   for ( cs = 1 ;cs <= t ; cs++ )
   {
        scanf("%d %d",&n,&q) ;
           printf("Case %d:\n",cs);
           ini(1,0,n-1);
           for ( i = 0 ; i < q ; i++ )
           {
                  scanf("%d %d %d",&op,&x,&y);
                  if(!op) update(1,0,n-1,x,y);
                  else printf("%lld\n",query(1,0,n-1,x,y));
           }

   }
}
