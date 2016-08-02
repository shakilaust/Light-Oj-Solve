

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

typedef long long int   __i64;
__i64 p , q ,dp[20][2][2] ,vis[20][2][2] , test;

int a[20],b[20] , maping , len;
__i64 DP(int pos,int gotSmall,int needSmall)
{
    if(pos==(len+1)/2)
    {   //printf("len::%d needSmall::%d\n",len,needSmall);
        if(needSmall) return gotSmall; // jokhon match ta calculation er somoy pore boro kisu bosano hoyeche
        return 1;
    }
    __i64 &ret = dp[pos][gotSmall][needSmall];
    if(ret!=-1) return ret;
   // vis[pos][gotSmall][needSmall] = test;
    if(gotSmall)
    {
        ret = 10*DP(pos+1,1,0);
        return ret;
    }
    ret = 0;
    int i , s = ( pos==0 && len>1) ? 1 : 0;
    for( i = s; i < a[pos] ; i++ ) ret += DP(pos+1,1,0);

            if( i < a[len-1-pos] ) ret += DP(pos+1,0,0);
            else if( i == a[len-1-pos] ) ret += DP(pos+1,0,needSmall);
            else ret += DP(pos+1,0,1);

    return ret;

}
__i64 solve(__i64 p)
{   if(p==0) return 1;
    if(p<10) return p+1;
    int idx=0 , i;
    while(p)
    {
        b[idx++]=p%10;
        p/=10;
    }
    reverse(b,b+idx);
    __i64 ans = 0;
    for( i = 0 ; i < idx - 1 ; i++ )
    {
        a[i] = 9;
        len = i + 1;
         memo(dp,-1);
        ans += DP(0,0,0);
        test++;
        //printf("len::: %d ans::%lld\n",len,ans);
    }
    for(i=0;i<idx;i++)
    {
        a[i] = b[i];
    }
    memo(dp,-1);
    len = idx;
    ans += DP(0,0,0);
    test++;
    return ans;
}
int main()
{
       // freopen("input.txt","r",stdin);
       int cs , t ;
       test = 1;
       scanf("%d",&t);
       for ( cs = 1 ,maping=1 ; cs <= t ; cs++ )
       {
           scanf("%lld %lld",&p,&q);
           if(p>q) swap(p,q);
           printf("Case %d: %lld\n",cs,solve(q) - solve(p-1));


       }
       return 0;

}
