
//BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopner soman boro
 Author :: Shakil Ahmed
 prob   :: Light Oj 1068, Investigation
 Type   :: Digit Dp
 verdict:: AC
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
#define long long int64
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
int dp[105][105];
bool vis[105][105];
char str[105];
#define S(V) V[s][e]
int pailndrome(int s,int e)
{
       if(s>e) return 0;
       if(  S(vis) ) return S(dp);
       S(vis)=1;
       if(str[s]==str[e])
          S(dp)=pailndrome(s+1,e-1);
       else
          S(dp)=min(pailndrome(s,e-1),pailndrome(s+1,e))+1;
       return S(dp);

}
int main()
{
    // freopen("input.txt","r",stdin);
    int cs,t;
    cin>>t;
    FOR(cs,1,t)
    {
          scanf("%s",str);
          memo(vis,0);
          printf("Case %d: %d\n",cs,pailndrome(0,strlen(str)-1));

    }

}
