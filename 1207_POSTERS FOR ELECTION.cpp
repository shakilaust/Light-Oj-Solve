
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
bool Possible[8*N] , Lazy[ 8*N ];
int  n , x[2*N] , y[2*N] ;

bool query(int node , int left , int right , int frm , int to )
{
       if(Lazy[node])
       {
              if(left!=right)
              {
                     Lazy[2*node] = Lazy[node];
                     Lazy[2*node+1] = Lazy[node];
              }
              Possible[node] = false ;
              Lazy[node] = false ;
       }
       if(frm > right || left > to ) return false; // out of the boundary
       if(frm<=left && to>=right) // in boundary
       {
              return Possible[node];
       }
       int mid = ( left + right ) / 2;
       return query(2*node,left,mid,frm,to) | query(2*node+1,mid+1,right,frm,to);


}
void update(int node,int left,int right, int frm , int to )
{
       if(frm > right || left > to ) return ; // out of the boundary
       if(frm<=left && to>=right) // in boundary
       {
              Possible[node] = false;
              if(left!=right)
              {
                     Lazy[2*node] = true;
                     Lazy[2*node+1] = true;

              }
                  Lazy[node] = false;
              return ;
       }
       int mid = ( left + right ) / 2;
       update(2*node,left,mid,frm,to) ;
       update(2*node+1,mid+1,right,frm,to);
       bool x = Lazy[2*node] ? false : Possible[2*node] ;
       bool y = Lazy[2*node+1] ? false : Possible[2*node+1];
       Possible[node] = ( x | y );

}
int main()
{
       int cs , t , n ;
       scanf("%d",&t);
       for ( cs = 1; cs <= t ; cs++ )
       {
              scanf("%d",&n);
              int i , ans = 0 ;
              int mx = -1;
              for ( i = 1 ; i <= n ; i++)
              {
                     scanf("%d %d",&x[i],&y[i]);
                     mx = max(mx , y[i] );
              }
              memo(Possible,true);
              memo(Lazy,false);
              mx +=1;
              for(i=n;i>0;i--)
              {
                     ans += query(1,1,mx,x[i],y[i]);
                     update(1,1,mx,x[i],y[i]);
              }
              printf("Case %d: %d\n",cs,ans);
       }


}
