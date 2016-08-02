
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
#define MAX 100000000
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
LL zero(LL n)
{
       LL sum=0,mul=5;
       while(mul<=n)
       {
              sum+=(n/mul);
              mul*=5;
       }
  return sum;
}
LL B_search(int n)
{
       LL low=1,high=10000000000,ans=-1;
       while(low<high)
       {
              LL mid=(low+high)/2;
              LL z=zero(mid);
              if(z==n) ans=mid;
              if(z<n) low=mid+1;
              else high=mid;
               //printf("low:: %lld high:: %lld mid::%lld\n",low,high,mid);

       }
        //printf("low:: %lld high:: %lld mid::%lld\n",low,high,ans);
       return ans;
}
int main()
{

    //freopen("in.txt", "r", stdin);
    int cs,t,n;

   // printf("idx:: %lld fact:: %lld\n",idx,fact[idx-1]);
    scanf("%d",&t);
    FOR(cs,1,t)
    {

          scanf("%d",&n);
          LL res=B_search(n);
          if(res<0) printf("Case %d: impossible\n",cs);
          else printf("Case %d: %lld\n",cs,res);




    }



}
