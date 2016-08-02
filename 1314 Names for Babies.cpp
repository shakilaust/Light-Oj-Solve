
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
int SA[32][N] , Res , Repeat, stp , cnt , sz , a , b; // SA r vitor all substring ase
string inp;
struct entry
{
       int nr[2], p;
} L [N] ; // Safiix array er position thake
bool cmp(entry A , entry B )
{
       if(A.nr[0] == B.nr[0] ) return A.nr[1] < B.nr[1];
       return A.nr[0] < B.nr[0];
}
int Value (int i )
{
       if(i > 0 && L[i].nr[0]==L[i-1].nr[0] && L[i].nr[1]==L[i-1].nr[1] ) return SA[stp][L[i-1].p] ;
       return i;
}
void Suffix()
{
       cin >> inp ; // taking input
       sz = inp.size ();
       int i ;
       for ( i = 0 ; i < sz ; i++ ) SA[0][i] = inp[i] - 'a' ;
       for( stp = 1 , cnt = 1 ; cnt >> 1 < sz ; cnt <<= 1 , stp++ )
       {
              for ( i = 0 ; i < sz ; i++ )
              {
                     L[i].nr[0] = SA[stp-1][i];
                     L[i].nr[1] = i + cnt < sz ? SA[stp-1][i+cnt] : -1;
                     L[i].p = i ;

              }
              sort ( L, L+sz , cmp);
              for ( i = 0 ; i < sz ; i++ )
              SA[stp][L[i].p] = Value(i);
       }

}
int LCP(int x, int y)
{
       int ret = 0 , k ;
       if( x == y ) return sz - x ;
       for ( k = stp - 1; k >=0 && x < sz && y < sz ; k--)
       if(SA[k][x] == SA[k][y] ) x += 1 << k , y += 1 << k , ret += 1 << k ;
       return ret;

}
LL solve()
{
       cin >> a >> b ;
       LL ans = 0 , tmp ; // when lower limit is 1 , every single charecter can be distinct substring
       int i , Size  ;
       for ( i = 0 ; i < sz; i++ )
       {
              int len = i > 0 ? LCP(L[i].p , L[i-1].p ) : 0 ;
               Size =  sz - ( L[i].p) ;
               tmp = min(Size,b) - max(a,len+1) + 1;
               if(tmp>0) ans += tmp;


       }
       return ans;
}
int main()
{ int cs, t ;
scanf("%d",&t);
for ( cs = 1 ; cs <= t ; cs++ )
{
       Suffix();
       printf("Case %d: %lld\n",cs,solve());
}
   return 0;
}
