
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
const int N =200005;
int sum[4*(N+N)] , Lazy[4*(N+N)] ,  x[N] , y[N] , q[N];
map <int,int> indxing;
void LazyPropagate(int node ,int left ,int right )
{      int mid = ( right + left ) / 2;
       if( left != right )
       {
              Lazy[2*node] += Lazy[node];
              Lazy[2*node+1] += Lazy[node];
       }
       sum[node] += ( ( right - left) +1) * Lazy[node];
       Lazy[node] = 0;
}
void ini(int node,int left,int right)
{
       Lazy[node] = 0;
       sum[node] = 0;
       if(left==right) return ;
       int mid = ( right + left ) /2;
       ini(2*node,left,mid);
       ini(2*node+1,mid+1,right);

}
void update(int node,int left,int right,int a,int b,int val)
{     //
        // printf("a::%d b::%d  lef::%d rgt::%d\n",a,b,left,right);
       if(Lazy[node]) LazyPropagate(node,left,right);
        if( a > right || b < left ) return ;
        if( a <= left && b>= right )
       {
              sum[node] += ((right-left)+1)*val;
              Lazy[node] += val;
              if(left!=right)
              {
                     Lazy[2*node] +=Lazy[node];
                     Lazy[2*node+1] +=Lazy[node];
              }
              Lazy[node] = 0;
              return ;
       }
       int mid = ( right + left ) /2;
       update(2*node,left,mid,a,b,val);
       update(2*node+1,mid+1,right,a,b,val);
       sum[node] = sum[2*node] + sum[2*node+1];
}
int query(int node,int left,int right,int a,int b)
{
        if(Lazy[node]) LazyPropagate(node,left,right);
        if( a > right || b < left ) return 0;
        if( a <= left && b>= right ) return sum[node];
       int mid = ( left + right ) / 2;
       int res = query(2*node,left,mid,a,b) + query(2*node+1,mid+1,right,a,b);
       return res;
}
int main()
{
       int cs , t , sz , n , m , i , id;
       scanf("%d",&t);
       for ( cs = 1 ; cs <= t ; cs++ )
       {
              set <int> s;
              set <int> :: iterator it;
              printf("Case %d:\n",cs);
              scanf("%d %d",&n,&m);
              for ( i = 0 ; i < n ; i++ )
              {
                     scanf("%d %d",&x[i],&y[i]);
                     s.insert(x[i]);
                     s.insert(y[i]);
              }
              for ( i = 0 ; i < m; i++ )
              {
                     scanf("%d",&q[i]);
                     s.insert(q[i]);
              }
              sz = s.size();
              indxing.clear();
              for ( it = s.begin() , id = 1; it != s.end() ; it++ , id++ )
              {
                     indxing[*it] = id ;
              }

              ini(1,0,sz);

              for( i = 0 ; i < n ; i++ )
              {
                     update(1,0,sz,indxing[x[i]],indxing[y[i]],1);


              }
              for(i=0 ; i < m ; i++ )
              {     // cout<<q[i]<<" "<<indxing[q[i]]<<endl;
                     printf("%d\n",query(1,0,sz,indxing[q[i]],indxing[q[i]]));
              }
       }


}
