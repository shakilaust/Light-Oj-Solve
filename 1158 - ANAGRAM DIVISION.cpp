
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
#define INF 1<<30
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define memo(a,b) memset((a),(b),sizeof(a))
#define G() getchar()
#define MAX3(a,b,c) max(a,max(b,c))

double const EPS=3e-8;
using namespace std;
int a[12],d;
int dp[(1<<10)+5][1010],len;
string str;
int DP(int mask,int mod)
{
       if(mask==(1<<len)-1)
       {
              if(mod==0) return 1;
              return 0;
       }
       if(dp[mask][mod]!=-1) return dp[mask][mod];
       int i,j,ret=0,c=0;
       for(i=0;i<len;i++)
       {
              if(mask & 1<<i) continue;
              ret+=DP((mask | 1<<i),((mod*10)+a[i])%d);

       }
       return dp[mask][mod]=ret;
}
int main()
{
       int cs,t,i,fact[12];
       fact[0]=1;
       for(i=1;i<=10;i++) fact[i]=fact[i-1]*i;
       scanf("%d",&t);
       for(cs=1;cs<=t;cs++)
       {
              int vis[12]={0};
              int i,ans=0;
              cin>>str>>d;
              len=str.size();
              for(i=0;i<len;i++) {
                a[i]=str[i]-'0';
                 vis[a[i]]++;
              }
              memo(dp,-1);
              ans=DP(0,0);
              for(i=0;i<10;i++) ans/=fact[vis[i]];

              printf("Case %d: %d\n",cs,ans);
       }
   return 0;
}
