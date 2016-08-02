
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;
char grid[15][15],in[15][15];
int cs,cost[15][15],n;
int dx[]= {1,-1,0,0};
int dy[]= {0,0,1,-1};
struct graph
{
    int x,y;
} parent,N;
bool valid(int x,int y)
{
    if(x>=0 && x<n && y>=0 && y<n && grid[x][y]!='#')
        return true;
    return false;
}
void input()
{
    int i;
    scanf("%d",&n);
    for(i=0; i<n; i++) scanf("%s",in[i]);
}
void fixed(char a, char b)
{
    int i,j;
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            if((in[i][j]>='A' && in[i][j]<='Z') && (in[i][j]!=a && in[i][j]!=b))
                grid[i][j]='#';
            else
                grid[i][j]=in[i][j];
        }
}
int bfs(int x,int y,char end)
{
    int i;
    N.x=x;
    N.y=y;
    queue <graph> q;
    q.push(N);
    memset(cost,0,sizeof(cost));

    while(!q.empty())
    {
        parent=q.front();
        q.pop();
        for(i=0; i<4; i++)
        {
            N.x=dx[i]+parent.x;
            N.y=dy[i]+parent.y;
            if(valid(N.x,N.y) && !cost[N.x][N.y])
            {
                cost[N.x][N.y]=cost[parent.x][parent.y]+1;
                if(grid[N.x][N.y]==end)
                {
                    return cost[N.x][N.y];
                }
                q.push(N);
            }
        }
    }
    return -1;
}
void solve()
{
    int i,ans=0,j,k,take=0,ct,collect=0;
    input();
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            if(in[i][j]>='A' && in[i][j]<='Z') collect+=1;
    for(i='A'; i<'A'+collect-1; i++)
    {
        for(j=0; j<n; j++)
        {
            bool check=false;
            for(k=0; k<n; k++)
            {
                if(in[j][k]==i)
                {
                    fixed(i,i+1);
                    take=bfs(j,k,i+1);
                    if(take!=-1)
                        ans+=take;
                    in[j][k]='.';
                    check=true;
                    break;
                }
            }
            if(check) break;
        }
        if(take==-1) break;
    }
    if(take==-1)  printf("Case %d: Impossible\n",cs);
    else
        printf("Case %d: %d\n",cs,ans);
}
int main()
{
    // freopen("input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(cs=1; cs<=t; cs++) solve();
}
