
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
#define MOD 1000000007
#define INF 1<<28
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define memo(a,b) memset((a),(b),sizeof(a))
#define G() getchar()
#define MAX3(a,b,c) max(a,max(b,c))

double const EPS=3e-8;
using namespace std;
int n , m , k ;
LL dp[1005][1005] ,nCr[1005][1005];
bool vis[1005][1005];
LL fact[1005];
void ini()
{
       int i , j ;
       for ( i = 0 ; i < 1001 ; i++ )
       {      if(i == 0 ) fact[i] = 1 ;
              else fact[i] = ( i * fact[i-1] ) %MOD ;
              for ( j = 0 ; j <= i ; j++ )
              if( i == j || j == 0 ) nCr[i][j] = 1;
              else nCr[i][j] = ( nCr[i-1][j]  + nCr[i-1][j-1] ) % MOD ;
       }
}
LL DP(int n , int m )
{
       if( n < 0 || m < 0 ) return 0;
       if(m == 0 ) return fact[n];
       if(vis[n][m] ) return dp[n][m];
       vis[n][m] = 1;
       // putting one of 1st m number in a wrong position
       LL left = DP(n-1,m-2) * (m-1);
       // taking one of 1st m number to right side
       LL right = DP ( n-1 , m-1) * ( n-m ) ;
       LL ret = ( left +right ) %MOD;
       return dp[n][m] = ret ;
}
int main()
{  ini();
   int cs , t ;
  scanf("%d",&t);
  for ( cs = 1 ; cs <= t ; cs++ )
  {
         scanf("%d %d %d",&n , &m , & k );
         LL res = ( nCr[m][k] * DP(n - k ,m - k ) ) %MOD;
         printf("Case %d: %lld\n",cs,res);


  }
   return 0;
}
