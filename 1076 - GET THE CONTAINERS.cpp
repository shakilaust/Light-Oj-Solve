
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


using namespace std;


template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
int N,M,a[1005];

bool isOk(LL mx)
{
       int cnt=1;
       LL sum=0,i;
       for(i=0;i<N;i++)
       {
              sum+=a[i];
              if(sum>mx)
              {
                  sum=a[i];
                  cnt++;
              }
              if(cnt>M) return false;
       }
       return true;
}


int main()
{

    //freopen("in.txt", "r", stdin);
    int cs,t,i;
    scanf("%d",&t);
    for(cs=1;cs<=t;cs++)
    {
            scanf("%d %d",&N,&M);
            int mx=-1;
            LL total=0;
            rep(i,N)
            {
                   scanf("%d",&a[i]);
                   total+=a[i];
                   if(a[i]>mx) mx=a[i];
            }
            if(M>=N)
            {
                   printf("Case %d: %d\n",cs,mx);
            }
            else
            {
                   LL low=mx;
                   LL high=total;
                   LL ans=high;
                   while(low<=high)
                   {
                          LL mid=(low+high)/2;
                          if(isOk(mid))
                          {
                                 high=mid-1;
                                 if(ans>mid) ans=mid;
                          }
                          else low=mid+1;
                   }
                   printf("Case %d: %lld\n",cs,ans);
            }

    }



}
