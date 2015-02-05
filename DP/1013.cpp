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
string A,B;
int LA,LB,dp[50][50],len;
bool vis[35][35][65];
long long int Dp[35][35][65];
long long int DP(int x,int y,int idx)
{
       if(idx==len)
       {
              if(x==LA && y==LB) return 1;
              else return 0;
       }
       if(vis[x][y][idx]) return Dp[x][y][idx];
       vis[x][y][idx]=1;
       if(x==LA) Dp[x][y][idx]=DP(x,y+1,idx+1);
       else if(y==LB) Dp[x][y][idx]=DP(x+1,y,idx+1);
       else if(A[x]==B[y]) Dp[x][y][idx]=DP(x+1,y+1,idx+1);
       else Dp[x][y][idx]=DP(x+1,y,idx+1)+DP(x,y+1,idx+1);
       return Dp[x][y][idx];
 
}
 
 
int main()
{
 
    //freopen("in.txt", "r", stdin);
    int cs,T,i,j;
    sc(T);
    FOR(cs,1,T)
    {
           cin>>A;
           cin>>B;
          // cout<<A<<" "<<B<<endl;
           LA=A.size();
           LB=B.size();
         //  cout<<LA<<" "<<LB<<endl;
           for(i=0;i<=LA;i++)
              for(j=0;j<=LB;j++)
              {
                     if(!i || !j) dp[i][j]=0;
                     else
                     {
                            if(A[i-1]==B[j-1]) dp[i][j]=dp[i-1][j-1]+1;
                            else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                     }
              }
           //   printf("LCS:: %d\n",dp[LA][LB]);
         len=(LA+LB)-dp[LA][LB];
         memo(vis,0);
         printf("Case %d: %d %lld\n",cs,len,DP(0,0,0));
 
 
    }
 
 
 
}
 
