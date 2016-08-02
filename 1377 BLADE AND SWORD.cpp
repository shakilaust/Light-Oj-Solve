
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
#include <string>
#include <queue>
#include <vector>
#include <iostream>
#define memo(a,b) memset((a),(b),sizeof(a))
#define pb push_back

using namespace std;
#define N 205

int R,C;
char grid[N][N];
bool visit[N][N];
int dx[]= {1,-1,0,0};
int dy[]= {0,0,1,-1};
struct graph
{
    int x,y,c,sv;

} in,cur,prev,s[100000];
bool ok(int x,int y)
{
    if(grid[x][y]=='#' || x<0 || x>=R || y<0 || y>=C || visit[x][y]) return false;
    return true;
}
int bfs()
{
    int ans=-1;
    int i,j;

    queue<graph> q;
    int idx=0;

    for(i=0; i<R; i++) for(j=0; j<C; j++)
        {
            if(grid[i][j]=='*')
            {
                s[idx].x=i;
                s[idx].y=j;
                s[idx++].sv=0;

                //  printf("start\n");
            }
            if(grid[i][j]=='P')
            {
                in.x=i;
                in.y=j;
                in.c=0;
                q.push(in);

                visit[i][j]=1;
            }
            else visit[i][j]=0;
        }
    if(idx==1)
    {
        grid[s[0].x][s[0].y]='#';
    }
    bool com=false;
    while(!q.empty())
    {
        prev=q.front();
        q.pop();
        if(grid[prev.x][prev.y]=='D')
        {
            // printf("reached:: %d\n",prev.c);
            return prev.c;
        }

        if(grid[prev.x][prev.y]=='*' && !com)
        {
            //   printf("not prev * x:: %d y:: %d\n",prev.x,prev.y);
            if(prev.sv==1)
            {
                prev.sv=2;
                prev.c+=1;
                q.push(prev);
            }
            else if(prev.sv==2)
            {  // printf("here\n");
                in=prev;
                in.c+=1;
                in.sv=3;
                q.push(in);

                for(i=0; i<idx; i++)
                {
                    prev.x=s[i].x;
                    prev.y=s[i].y;
                    if(in.x==prev.x && in.y==prev.y) continue;
                    for(j=0; j<4; j++)
                    {

                        cur.x=prev.x+dx[j];
                        cur.y=prev.y+dy[j];
                        if(ok(cur.x,cur.y))
                        {    visit[cur.x][cur.y]=1;
                            if(grid[cur.x][cur.y]=='*')
                            {
                                continue;
                            }


                            cur.c=prev.c+1;
                            q.push(cur);
                        }
                    }

                }


            }
            else
            {
                for(i=0; i<4; i++)
                {

                    cur.x=prev.x+dx[i];
                    cur.y=prev.y+dy[i];
                    if(ok(cur.x,cur.y))
                    {    visit[cur.x][cur.y]=1;
                        if(grid[cur.x][cur.y]=='*')
                        {
                           continue;
                        }


                        cur.c=prev.c+1;

                        q.push(cur);
                    }
                }
                com=true;

            }




        }
        else
        {
            for(i=0; i<4; i++)
            {

                cur.x=prev.x+dx[i];
                cur.y=prev.y+dy[i];
                if(ok(cur.x,cur.y))
                {
                    if(grid[cur.x][cur.y]=='*')
                    {
                            cur.sv=1;
                    }

                    visit[cur.x][cur.y]=1;
                    cur.c=prev.c+1;

                    q.push(cur);
                }
            }

        }
    }
    return ans;

}
int main()
{

    //freopen("in.txt", "r", stdin);
    int cs,t;
    scanf("%d",&t);
    for(cs=1; cs<=t; cs++)
    {
        int i;
        scanf("%d %d",&R,&C);
        for(i=0; i<R; i++) scanf("%s",grid[i]);
        int ans=bfs();
        if(ans==-1) printf("Case %d: impossible\n",cs);
        else printf("Case %d: %d\n",cs,ans);


    }
}
