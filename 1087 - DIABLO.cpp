
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
vector <int> ans;
int main()
{  int cs , t , i ;
   scanf("%d",&t);
   for ( cs = 1 ; cs <= t ; cs++ )
   {
          int n , q, inp;
          scanf("%d %d",&n,&q);
          printf("Case %d:\n",cs);
          ans.clear();
          for ( i = 0 ; i < n ; i++ )
          {
                 scanf("%d",&inp);
                 ans.pb(inp);
          }
          char str[3];
          for ( i = 0 ; i < q ; i++ )
          {
                 scanf("%s %d",str,&inp);
                 if(str[0]=='a')
                 {
                        ans.pb(inp);

                 }
                 else
                 {
                        if(ans.size()>=inp)
                        {
                               printf("%d\n",ans[inp-1]);
                               ans.erase(ans.begin()+inp-1);
                        }
                        else printf("none\n");
                 }
          }
   }
   return 0;
}
