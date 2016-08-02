
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
#define MAX 1000000
#define INF 1LL<<31-1
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define memo(a,b) memset((a),(b),sizeof(a))
#define G() getchar()


using namespace std;


template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
long long int dp[1005][2],w1[1005],w2[1005],L[1005],R[1005],n;
bool vis[1005][2];
long long int DP(int idx,int taken)
{
       if(idx==n) return 0;
       if(vis[idx][taken]) return dp[idx][taken];
       vis[idx][taken]=1;
       if(taken)
       dp[idx][taken]=min(w1[idx]+DP(idx+1,1),w2[idx]+L[idx]+DP(idx+1,0));
       else
       dp[idx][taken]=min(w1[idx]+R[idx]+DP(idx+1,1),w2[idx]+DP(idx+1,0));
       return dp[idx][taken];
}

int main()
{

  //  freopen("in.txt", "r", stdin);
    int cs,T,i;
    sc(T);
    FOR(cs,1,T)
    {
           scanf("%d",&n);
           rep(i,n) cin>>w1[i];
           rep(i,n) cin>>w2[i];
           for(i=1;i<n;i++) cin>>L[i];
           for(i=1;i<n;i++) cin>>R[i];
           L[0]=R[0]=0;
           memo(vis,0);
           long long int ans=DP(0,0);
           ans=min(ans,DP(0,1));
           pfcs(cs,ans);

    }



}
