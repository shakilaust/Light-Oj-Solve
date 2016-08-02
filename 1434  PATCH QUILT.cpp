
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

double const EPS=3e-8;
using namespace std;


template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
int dx[]={0,0,0,1,1,1,-1,-1,-1};
int dy[]={-1,0,1,-1,0,1,-1,0,1};
string dirC[9]={"L","*","R","DL","D","DR","UL","U","UR"};
vector <string>  res;
int R,C,len;
//int str[30],vis[30];
bool yes[30];
string grid[30],inp;
bool ok(int x,int y)
{
       if(x<0 || x>=R || y<0 || y>=C) return false;
       return true;
}
bool dfs(int idx,int x,int y)
{      if(idx==len) return true;

       int i;
       for(i=0;i<9;i++)
       {
              int nx=x+dx[i];
              int ny=y+dy[i];
              if(ok(nx,ny))
              {
                     char cur=grid[nx][ny];
                     if(cur==inp[idx] &&  dfs(idx+1,nx,ny))
                     {

                            res.pb(dirC[i]);
                            return true;
                     }
              }
       }
       return false;
}

int main()
{

    //freopen("in.txt", "r", stdin);
    int cs,t;
    sc(t);
    rep(cs,t)
    {
           scanf("%d %d",&R,&C);
           int i,k,j,sz,m,x,y;
           memo(yes,0);
           for(i=0;i<R;i++)
           {
           cin>>grid[i];
              for(j=0;j<C;j++) yes[grid[i][j]-'A']=1;
           }
           scanf("%d",&m);
           printf("Case %d:\n",cs+1);
           rep(k,m)
           {
              //    memo(vis,0);
                 // memo(str,0);
                  bool flag=false;
                  cin>>inp;
                  len=inp.size();
                  for(i=0;i<len;i++) if(!yes[inp[i]-'A'])
                  {
                         flag=true;
                         break;
                  }
                  if(flag)
                  {
                         cout<<inp<<" not found"<<endl;
                         continue;
                  }
                  bool br=false;
                  for(i=0;i<R  && !br ;i++)
                  {

                         for(j=0;j<C;j++)
                         {
                                if(grid[i][j]==inp[0])
                                {
                                       res.clear();

                                       if(dfs(1,i,j))
                                       {
                                              flag=true;
                                              br=true;
                                              x=i+1;
                                              y=j+1;

                                              break;
                                       }


                                }
                         }
                  }
                  if(flag)
                  {
                         cout<<inp<<" found: ("<<x<<","<<y<<")";
                         for(i=res.size()-1;i>=0;i--) cout<<", "<<res[i];
                         cout<<endl;
                  }
                  else cout<<inp<<" not found"<<endl;

           }
    }



}
/*
1
7 8
XTFATIPP
WUNTOZMM
UKCJICHO
SXGNAFUA
YAAUIQLG
KYZAZLPT
VTCFVLTP
2
IAAGCUT
TCTTJCXUWW
*/
