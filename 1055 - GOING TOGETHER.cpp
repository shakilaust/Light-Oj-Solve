
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
#define MAX3(a,b,c) max(a,max(b,c))
#define V(s) vis[s.x[0]][s.y[0]][s.x[1]][s.y[1]][s.x[2]][s.y[2]]

double const EPS=3e-8;
using namespace std;


template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }

char grid[15][15];
const int N=3;
int n,cs,Res[3];
bool vis[11][11][11][11][11][11],ok[N];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
struct graph
{
       int x[N],y[N];
       int cost;
}cur,prev,in;
void Adjust()
{      int i,j,k;
       for(i=0;i<3;i++)
       {
       int nx=cur.x[i];
       int ny=cur.y[i];
       if(ny<0 || ny>=n || nx<0 || nx>=n ||  grid[nx][ny]=='#')
       {
              cur.x[i]=prev.x[i];
              cur.y[i]=prev.y[i];
       }
       }
       for(k=0;k<3;k++) // insider conflict
         for(i=0;i<3;i++)
            for(j=0;j<3;j++)
            {
                   if(i==j) continue;
                   if(cur.x[i]==cur.x[j] && cur.y[i]==cur.y[j])
                   {
                          cur.x[j]=prev.x[j];
                          cur.y[j]=prev.y[j];
                   }
            }

}
bool CheckDestination()
{
          int i;
          for(i=0;i<3;i++)  if(grid[prev.x[i]][prev.y[i]]!='X') return false;
          return true;
}
void solve()
{      int i,j,idx=0,ans=-1;
       queue <graph> q;
       scanf("%d",&n);
       rep(i,n) scanf("%s",grid[i]);
       memo(vis,0);
       for(i=0;i<n;i++)
          for(j=0;j<n;j++)
          {
                 if(grid[i][j]=='A' || grid[i][j]=='B' || grid[i][j]=='C')
                 {   in.x[grid[i][j]-'A']=i;
                     in.y[grid[i][j]-'A']=j;
                 }
          }
          in.cost=0;
          q.push(in);

          while(!q.empty())
          {      prev=q.front();
                 q.pop();
                 if(CheckDestination())
                 {
                        ans=prev.cost;
                        break;
                 }

                 for(i=0;i<4;i++) {
                    for(j=0;j<3;j++)
                      {
                        cur.x[j]=prev.x[j]+dx[i];
                        cur.y[j]=prev.y[j]+dy[i];


                     }
                      Adjust();
                if(!V(cur))
                {
                       V(cur)=1;
                       cur.cost=prev.cost+1;
                       q.push(cur);
                }
                 }

          }

          if(ans!=-1)
          {
                 printf("Case %d: %d\n",cs,ans);

          }
          else
            printf("Case %d: trapped\n",cs);
}

int main()
{

    //freopen("in.txt", "r", stdin);
    int t;
    sc(t);
    for(cs=1;cs<=t;cs++)
    {
           //printf("Case %d: ",cs);
           solve();
    }


}
