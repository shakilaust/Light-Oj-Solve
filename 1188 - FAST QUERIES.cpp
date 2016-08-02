
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
const int N = 200005;
int prev[N]  , tree[N] , ans[N] , n , q;
struct abc
{
       int x,y,op,num;
}inp[N];
bool cmp(abc A,abc B)
{
       if(A.y==B.y) return A.op<B.op;
       return A.y < B.y;

}
void clear()
{      int i;
       for ( i = 0 ; i <= n ; i++ )
       {
              prev[i] = 0;
              tree[i] = 0;
       }

}
void write(int idx, int val)
{
       while(idx <= n )
       {
              tree[idx] += val;
              idx += (idx & -idx);
       }
}
int read(int idx)
{
       int sum = 0;
       while(idx>0)
       {
              sum += tree[idx];
              idx -= (idx & -idx);
       }
       return sum;
}
void solve()
{
      // clear();
      memo(tree,0);
      memo(prev,0);
       int i;
       for ( i = 0 ; i < n+q ; i++ )
       {
              if(inp[i].op==1)
              {
                     if(prev[inp[i].x]==0)
                     {
                            write(inp[i].y,1);
                            prev[inp[i].x] = inp[i].y;
                     }
                     else
                     {
                            write(prev[inp[i].x],-1);
                            write(inp[i].y,1);
                            prev[inp[i].x] = inp[i].y;

                     }
              }
              else
              {
                     ans[inp[i].num] = read(inp[i].y) - read(inp[i].x-1);
              }
       }
}
int main()
{
       int cs , t ,i;
       scanf("%d",&t);
       for ( cs = 1 ; cs <= t ; cs++ )
       {
              scanf("%d %d",&n,&q);
              for(i=0;i<n;i++)
              {
                     scanf("%d",&inp[i].x);
                     inp[i].y = i+1 ; // input position;
                     inp[i].op = 1; // ki type input;
              }
              for ( i = n ; i < n+q ; i++ )
              {
                     scanf("%d %d",&inp[i].x,&inp[i].y);
                     inp[i].op = 2;
                     inp[i].num = i - n ; // query number
              }
              sort(inp,inp+n+q,cmp);

              solve();
              printf("Case %d:\n",cs);
              for( i = 0 ; i < q ; i++ ) printf("%d\n",ans[i]);
       }
   return 0;
}
