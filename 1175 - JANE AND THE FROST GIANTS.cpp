
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#define INF 1<<29
#define MAX 205
using namespace std;
int cost_joe[MAX][MAX],cost_Fire[MAX][MAX],row,col;
struct graph
{
    int x,y,c;
}par,child;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
string grid[MAX];
bool valid(int x,int y)
{
    if(x>=0 && x<row && y>=0 && y<col  && grid[x][y]!='#')
    {
    return true; }
    return false;
}
void input()
{
    int i;
    scanf("%d %d",&row,&col);
    for(i=0;i<row;i++)
      cin>>grid[i];
    }
void bfs_joe(int x,int y)
{   int i,j;
    for(i=0;i<=row;i++)
       for(j=0;j<=col;j++)
          cost_joe[i][j]=INF;
    par.x=x,par.y=y,par.c=0;
    queue <graph> q;
    q.push(par);
    cost_joe[x][y]=0;

    while(!q.empty())
    {
        par=q.front();
        q.pop();
        for(i=0;i<4;i++)
        {
            child.x=par.x+dx[i];
            child.y=par.y+dy[i];

            if(valid(child.x,child.y) && cost_joe[child.x][child.y]==INF)
            {
                child.c=cost_joe[child.x][child.y]=cost_joe[par.x][par.y]+1;
                q.push(child);
            }
        }
    }
}
void bfs_fire()
{   int i,j;
     //printf("x:: %d  y:: %d\n",x,y);
     queue <graph> q;
     for(i=0;i<=row;i++)
       for(j=0;j<=col;j++)
          cost_Fire[i][j]=INF;
          for(i=0;i<row;i++)
             for(j=0;j<col;j++)
                if(grid[i][j]=='F')
               {
                     par.x=i,par.y=j,par.c=0;
                       q.push(par);
                        cost_Fire[i][j]=0;

               }
    while(!q.empty())
    {
        par=q.front();
        q.pop();
        for(i=0;i<4;i++)
        {
            child.x=par.x+dx[i];
            child.y=par.y+dy[i];

            if(valid(child.x,child.y) && cost_Fire[child.x][child.y]==INF)
            {
                child.c=cost_Fire[child.x][child.y]=cost_Fire[par.x][par.y]+1;
                q.push(child);
            }
        }
    }
}
void solve()
{   int i,j,ct=0,iter;
    for(i=0;i<row;i++)
       for(j=0;j<col;j++)
           if(grid[i][j]=='F') ct++;
    for(i=0;i<row;i++)
       for(j=0;j<col;j++)
         {
              if(grid[i][j]=='J')
              {
                  bfs_joe(i,j);
                  break;
              }
         }
        bfs_fire();
        /*for(i=0;i<row;i++)
           for(j=0;j<col;j++)
             {
                 printf("i:: %d j:: %d cost_joe:: %d cost_fire::%d\n",i,j,cost_joe[i][j],cost_Fire[i][j]);
             } */
    int mx=INF;
        for(i=0;i<col;i++)
            {  // printf("i::0  j::%d  cost_joe::%d cost_fire::%d\n",i,cost_joe[0][i],cost_Fire[0][i]);
                if(cost_Fire[0][i]>cost_joe[0][i]) mx=min(mx,cost_joe[0][i]);
                if(cost_Fire[row-1][i]>cost_joe[row-1][i]) mx=min(mx,cost_joe[row-1][i]);
               //  printf("i::%d  j::%d  cost_joe::%d cost_fire::%d\n",row-1,i,cost_joe[row-1][i],cost_Fire[row-1][i]);
            }
        for(i=0;i<row;i++)
        {  //  printf("i::%d  j::0  cost_joe::%d cost_fire::%d\n",i,cost_joe[i][0],cost_Fire[i][0]);
            if(cost_Fire[i][0]>cost_joe[i][0]) mx=min(mx,cost_joe[i][0]);
          //  printf("i::%d  j::%d cost_joe::%d cost_fire::%d\n",i,col-1,cost_joe[i][col-1],cost_Fire[i][col-1]);
            if(cost_Fire[i][col-1]>cost_joe[i][col-1]) mx=min(mx,cost_joe[i][col-1]);
        }
    if(mx==INF) puts("IMPOSSIBLE");
    else
    printf("%d\n",mx+1);
}
int main()
{ //  freopen("input.txt","r",stdin);
    int cs,t;
    scanf("%d",&t);
    for(cs=1;cs<=t;cs++)
    {   input();
        printf("Case %d: ",cs);
        solve();
    }
}
