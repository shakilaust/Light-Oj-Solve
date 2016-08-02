
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

LL dp[(1<<16)+5][22],n,k,sz;
int cs;
int visit[(1<<16)+5][22];
int value(char c)
{
       if(c>='A') return c-'A'+10;
       else return c-'0';
}
char word[22];
LL DP(int mask,int rem)
{
       if(mask==(1<<sz)-1) return !rem;
       LL &ret=dp[mask][rem];
       if(visit[mask][rem]==cs) return ret;
       visit[mask][rem]=cs;
       ret=0;
       int i;
       for(i=0;i<sz;i++)
       {
              if(!(mask & (1<<i)))
              {
                     ret+=(DP(mask | (1<<i),(value(word[i])+rem*n)%k));
              }
       }
   //    cout<<"ret :: "<<ret<<endl;
       return ret;
}
int main()
{

    //freopen("in.txt", "r", stdin);
    int t;
    sc(t);
    for(cs=1;cs<=t;cs++)
    {
           scanf("%lld %lld",&n,&k);
           scanf("%s",word);
           sz=strlen(word);
        //   memo(dp,-1);
           printf("Case %d: %lld\n",cs,DP(0,0));

    }



}
