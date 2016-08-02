//BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopner soman boro
 Author :: Shakil Ahmed
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
#define sc(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
#define pi acos(-1.0)
#define LL long long
#define ff first
#define ss second
#define rep(i,n) for(i = 0; i < n; i++)
#define REP(i,n) for(i=n;i>=0;i--)
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define ROF(i,a,b) for(int i = a; i >= b; i--)
#define re return
#define QI queue<int>
#define SI stack<int>
#define pii pair <int,int>
#define MAX 1000000
#define INF 1<<29
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define memo(a,b) memset((a),(b),sizeof(a))
#define G() getchar()


using namespace std;


template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
LL dp[25][155];
bool vis[25][155];
int n,x;
#define S(V) V[cur][sum]
LL DP(int cur,int sum)
{
       if(cur==n)
       {
              if(sum>=x) return 1;
              else return 0;
       }
       if(S(vis)) return S(dp);
       S(vis)=1;
       S(dp)=0;
       int i;
       for(i=1;i<=6;++i)
       {
              S(dp)+=DP(cur+1,sum+i);

       }
       return S(dp);

}


int main()
{

    //freopen("in.txt", "r", stdin);
    int cs,t,i;
    cin>>t;
    FOR(cs,1,t)
    {
           cin>>n>>x;
           LL total=1;
           FOR(i,1,n) total*=6;
           memo(vis,0);
           LL ans=DP(0,0);
           LL g=gcd(ans,total);
           ans/=g;
           total/=g;
           if(ans%total==0) printf("Case %d: %lld\n",cs,ans/total);
           else printf("Case %d: %lld/%lld\n",cs,ans,total);

    }

}
