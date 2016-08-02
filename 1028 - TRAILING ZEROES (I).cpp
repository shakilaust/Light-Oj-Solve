
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
int prime[100000],idx=0;
bool vis[1000005];
void seive()
{      idx=0;
       prime[idx++]=2;
       memo(vis,0);
       int i,j;
       for(i=3;i*i<1000000;i+=2)
       {
              if(!vis[i])
              {
                     prime[idx++]=i;
                     vis[i]=1;
                     for(j=i*i;j<1000000;j+=2*i)
                     {
                            vis[j]=1;
                     }
              }
       }
       for(;i<1000000;i+=2)
       {
               if(!vis[i])
              {
                     prime[idx++]=i;
              }
       }

}
int main()
{  seive();
   int cs,t,i;
   scanf("%d",&t);
   FOR(cs,1,t)
   {
          long long int n;
          cin>>n;
         int ans = 1;
		for (i = 0; i < idx && prime[i]*prime[i] <= n; i++)
		{
			if (n % prime[i] == 0)
			{
				int tp = 1;

				while (n % prime[i] == 0)
				{
				       ++tp, n /= prime[i];
				}
				ans *= tp;
			}
		}
		if (n > 1) ans *= 2;
		--ans;

          printf("Case %d: %d\n",cs,ans);
   }
}
