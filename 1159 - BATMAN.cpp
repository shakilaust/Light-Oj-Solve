
//BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopner soman boro
 Author :: Shakil Ahmed
 prob   :: Light Oj 1159 , BATMAN
 Type   :: Dp
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
#define ff first
#define ss second
#define rep(i,n) for(i = 0; i < n; i++)
#define REP(i,n) for(i=n;i>=0;i--)
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define ROF(i,a,b) for(int i = a; i >= b; i--)
#define re return
#define i64 long long
#define QI queue<int>
#define SI stack<int>
#define pii pair <int,int>
#define INF 1<<29
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define memo(a,b) memset((a),(b),sizeof(a))
#define G() getchar()
#define MAX(a,b,c) ( (a) > ( b) ? ( (a) > (c) ? (a) : ( c) ) : (  ( b) > ( c) ? ( b) : ( c) ) )

using namespace std;


template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }

int dp[55][55][55];
bool vis[55][55][55];
string s1,s2,s3;
int A,B,C;
#define S(V)  V[a][b][c]
int DP(int a,int b,int c)
{
       if(a>=A || b>=B || c>= C) return 0;
       if(S(vis)) return S(dp);
       S(vis)=1;
       if(s1[a]==s2[b] && s2[b]==s3[c])
       S(dp)=DP(a+1,b+1,c+1)+1;
       else
       S(dp)=MAX(DP(a,b,c+1),DP(a,b+1,c),DP(a+1,b,c));
       return S(dp);

}

int main()
{

    //freopen("in.txt", "r", stdin);
    int cs,t;
    cin>>t;
    FOR(cs,1,t)
    {
          cin>>s1>>s2>>s3;
          A=s1.size();
          B=s2.size();
          C=s3.size();
          memo(vis,0);
          printf("Case %d: %d\n",cs,DP(0,0,0));
    }

}
