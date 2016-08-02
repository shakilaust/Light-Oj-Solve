
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

double const EPS=1e-6;
using namespace std;
const int N = 35;

int inp[N][N], n, m, k, ans[N], p;
void input()
{
       cin >> n >> m >> k;
       int i, j ;

       for ( i = 0 ; i < n ; i++ )
       {
              for ( j = 0 ; j < k ; j++ ) cin >> inp[i][j];
       }
       cin >> p ;
       for ( i = 0 ; i < p ; i++ ) cin>> ans[i];

}
bool solve()
{
       int i, j, x;
       for ( i = 0 ; i < n ; i++ )
       {
              bool ok = false ;
              for ( j = 0 ; j < k && !ok ; j++ )
              {
                     int wish = inp[i][j];
                 //    printf ( " Person :: %d wish :: %d\n", i , wish );
                     bool nai = true ;
                     bool ase = false;
                     for ( x = 0 ; x < p ; x++ )
                     {
                            if ( abs(wish) == ans[x] )
                            {
                                   nai = false;
                                   ase = true;
                            }
                     }

                     if ( wish < 0 && nai ) ok = true;
                     if ( wish > 0 && ase ) ok = true;
              }
              if ( ok == false ) return 0;

       }
       return 1;

}

int main()
{
       int cs, t;
       scanf("%d",&t);
       for ( cs = 1 ;cs <= t ; cs++ )
       {     input();
             printf("Case %d: %s\n",cs,solve()?"Yes":"No");

       }


   return 0;
}
