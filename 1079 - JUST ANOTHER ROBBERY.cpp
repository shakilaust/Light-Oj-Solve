
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

const int N = 10005;
int money [ N ] ;
int n;
double Limit, dp[N], P[N];
int solve ( int sum )
{
       int i,j;

            for ( j = 0 ; j <= sum ; j++ ) dp[j] = INF ;
       dp[0] = 0;
       for ( i = 0 ; i < n ; i++ )
       {
              for ( j = sum ; j >= money[i] ; j-- )
              dp[j] = min(dp[j] , dp[j-money[i]] + (1 - dp[j - money[i] ]) * P[i] );
       }
       for ( i = sum ; i >= 0 ; i-- ) if(dp[i] < Limit ) return i;
       return 0;
}
int main()
{  int cs, t, i, sum;
   scanf ("%d", &t);
   for ( cs = 1; cs <= t ; cs++ )
   {      scanf ("%lf %d",&Limit, &n);

          for ( i = 0, sum = 0 ; i < n ; i++ )
          {
                 scanf("%d %lf",&money[i], &P[i]);
                 sum += money[i];
          }
          printf("Case %d: %d\n", cs, solve( sum ) );
   }
   return 0;
}
