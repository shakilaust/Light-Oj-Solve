
#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;
char grid[25][25];
int row,col,cs,cost[25][25];
int dx[]= {1,-1,0,0};
int dy[]= {0,0,1,-1};
struct graph
{
    int x,y;
} in,n,nn;
bool valid(int r,int c)
{
    if(r>=0 && r<row && c>=0 && c<col && grid[r][c]!='m' && grid[r][c]!='#')
    {
        return true;
    }
    return false;
}
int bfs(int _x,int _y)
{
    int i;
    in.x=_x,in.y=_y;
    memset(cost,0,sizeof(cost));
    queue <graph> q;
    q.push(in);
    while(!q.empty())
    {
        n=q.front();
        q.pop();

        for(i=0; i<4; i++)
        {
            int x=dx[i]+n.x;
            int y=dy[i]+n.y;
            if(valid(x,y) && !cost[x][y])
            {
                cost[x][y]=cost[n.x][n.y]+1;
                if(grid[x][y]=='h')
                {
                    return cost[x][y];
                }
                nn.x=x;
                nn.y=y;
                q.push(nn);

            }
        }

    }
    return 0;
}
void input()
{
    int i;
    scanf("%d %d",&row,&col);
    for(i=0; i<row; i++) scanf("%s",grid[i]);
}
void solve()
{
    int i,mx=-1,j,k,dus=0;
    input();
    for(i='a'; i<='c'; i++)
    {
        dus++;
        for(j=0; j<row; j++)
        {
            bool check=false;
            for(k=0; k<col; k++)
                if(grid[j][k]==i)
                {
                    mx=max(mx,bfs(j,k));
                    check=true;
                    break;
                }
            if(check) break;
        }
    }
    printf("Case %d: %d\n",cs,mx);
}
int main()
{
    //freopen("shaki.txt","r",stdin);
    int t;
    scanf("%d",&t);
    //getchar();


    for(cs=1; cs<=t; cs++)
    {
        solve();


    }
}
