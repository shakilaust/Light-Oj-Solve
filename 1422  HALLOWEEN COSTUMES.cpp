
 //BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopner soman boro
 Author :: Shakil Ahmed
.............AUST_CSE27.........
 prob   ::
 Type   ::
 verdict::
 */
#include <bits/stdc++.h>

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
#define INF 1<<28
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define memo(a,b) memset((a),(b),sizeof(a))
#define G() getchar()
#define MAX3(a,b,c) max(a,max(b,c))

double const EPS=3e-8;
using namespace std;
const int N = 105 ;
int dp[N][N] , inp[N] , n;
int DP(int left , int right )
{
       int &ret = dp[left][right ];
       if(ret != -1 ) return ret;
       if(left > right ) return 0;
       ret = DP(left + 1 , right ) + 1;
       int i ;
       for ( i = left+1 ; i <= right ; i++ )
       {
              if( inp[left] == inp[i] ) ret = min ( ret , DP(left+1,i) + DP(i+1,right ));
       }
       return ret;
}
int main()
{
       int cs, t , i ;
       scanf("%d",&t);
       for ( cs =1 ; cs<=t ; cs++ )
       {
              scanf("%d",&n);
              for ( i = 0 ; i < n ; i++ ) cin >> inp[i];
              memo(dp,-1);
              printf("Case %d: %d\n",cs,DP(0,n-1));
       }
   return 0;
}
