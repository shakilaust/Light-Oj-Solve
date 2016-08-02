
//BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopner soman boro
 Author :: Shakil Ahmed
 prob   :: LightOj 1044
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
#define MAX 1005
#define INF 1<<29
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define memo(a,b) memset((a),(b),sizeof(a))
#define G() getchar()


using namespace std;


template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
bool ispalindrom[MAX][MAX],vis[MAX];
int dp[MAX],len;
string str;
#define S(V) V[cur]
void MakingPalinDrome()
{
       int i,j,k;
       FOR(i,0,len-1)
       {
              ispalindrom[i][i]=true;
              for(j=i-1,k=i+1; j>=0 && k<len && str[j]==str[k];j--,k++) ispalindrom[j][k]=true; // odd er junno
              for(j=i,k=i+1;j>=0 && k<len && str[j]==str[k];j--,k++) ispalindrom[j][k]=true; // even er junno
       }
}

int DP(int cur)
{
       if(cur>=len) return 0;
       if(S(vis)) return S(dp);
       S(vis)=1;
       int i,ret=INF;
       FOR(i,cur,len-1)
       {      if(ispalindrom[cur][i])
              ret=min(ret,DP(i+1)+1);
       }
       return S(dp)=ret;
}
int main()
{

    //freopen("in.txt", "r", stdin);
    int cs,t;
    cin>>t;
    FOR(cs,1,t)
    {
           cin>>str;
           len=str.size();
           memo(ispalindrom,0);
           MakingPalinDrome();
           memo(vis,0);
           printf("Case %d: %d\n",cs,DP(0));

    }

}
