
//BISMILLAHIRRAHMANIRRAHIM
#include <stdio.h>
#include <string.h>
#include <utility>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#define rep(i,n)  for(i=0;i<n;i++)
#define mp make_pair
#define pb push_back
#define INF 1<<29
#define memo(a,b) memset(a,b,sizeof(a))
using namespace std;
int vis[12][12];
int R,C,cost[15][15];
int dx[]={1,1,-1,-1,2,2,-2,-2};
int dy[]={2,-2,2,-2,1,-1,1,-1};
char input[15][15];
bool valid(int x,int y)
{
       if(x>=0 && x<R && y>=0 && y<C && vis[x][y]==-1) return 1;
       else return 0;
}
int bfs(int sx,int sy,int ex,int ey)
{      memo(vis,-1);
       queue < pair<int,int> > q;
       q.push(mp(sx,sy));
       vis[sx][sy]=0;
       if(sx==ex && sy==ey) return 0;
       int i;
       while(!q.empty())
       {
              int x=q.front().first,y=q.front().second;
              q.pop();
              rep(i,8)
              {
                     int nx=x+dx[i];
                     int ny=y+dy[i];
                     if(valid(nx,ny))
                     {  vis[nx][ny]=vis[x][y]+1;
                        if(nx==ex && ny==ey) return vis[nx][ny];
                        q.push(mp(nx,ny));
                     }
              }


       }
       //printf("ex::%d  ey::%d   vis::%d\n",vis[ex][ey]);
       return -1;

}
void solve(int cs)
{     int i,j,k;
      vector < pair< int, pair< int,int> > > v;
       cin>>R>>C;
       rep(i,R) scanf("%s",input[i]);
       rep(i,R)  rep(j,C)
       if(input[i][j]>='1' && input[i][j]<='9')
       {
              v.pb(mp(input[i][j]-'0',mp(i,j)));
       }
       int res=INF;
        rep(i,R)  rep(j,C)
        {
               bool ok=true;
               int tmp=0;
               rep(k,v.size())
               {
                      int p=v[k].first;
                      int dis=bfs(v[k].second.first,v[k].second.second,i,j);
                      if(dis==-1)
                      {
                             ok=false;
                             break;
                      }
                      tmp+=(dis+p-1)/p; // p er man 1 er beshi hole move komanor junno dichi
               }
               if(ok && res>tmp) res=tmp;
        }
        printf("Case %d: %d\n",cs,res==INF?-1:res);

}
int main()
{      //freopen("input.txt","r",stdin);
       int cs,t;
       cin>>t;
       rep(cs,t)
       {
              solve(cs+1);
       }
}
