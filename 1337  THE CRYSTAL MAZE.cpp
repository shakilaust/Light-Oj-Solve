
//BISMILLAHIRRAHMANIRRAHIM
/* Author :Shakil_AUST
   problem: LightOj,1337
   Type   : DFS
*/
#include <stdio.h>
#include <string.h>
char maze[505][505];
bool visit[505][505];
int cost[505][505];
int count,M,N,Q;
int x_axis[4]={1,-1,0,0};
int y_axis[4]={0,0,1,-1};
void dfs(int x,int y)
{
   if(maze[x][y]=='C') count++;
   visit[x][y]=true;
   for(int i=0;i<4;i++)
   {  int nx=x+x_axis[i];
      int ny=y+y_axis[i];
      if(nx>=0 && nx<M && ny>=0 && ny<N && maze[nx][ny]!='#' && !visit[nx][ny])
      {
        dfs(nx,ny);
      }
   }
}
void dfsDP(int x,int y)
{
   cost[x][y]=count;
   for(int i=0;i<4;i++)
   {  int nx=x+x_axis[i];
      int ny=y+y_axis[i];
      if(nx>=0 && nx<M && ny>=0 && ny<N && maze[nx][ny]!='#')
      {
        dfs(nx,ny);
      }
   }
}

int main()
{  int T;
    scanf("%d",&T);

   for(int kase=1;kase<=T;kase++)
   {  scanf("%d %d %d",&M,&N,&Q);
      memset(cost,-1,sizeof(cost));
      for(int i=0;i<M;i++) scanf("%s",maze[i]);
      int x,y;
      printf("Case %d:\n",kase);
     while(Q--)
      {  count=0;
         memset(visit,false,sizeof(visit));
         scanf("%d %d",&x,&y);
         if(cost[x-1][y-1]==-1)
	   {
         dfs(x-1,y-1);
         cost[x-1][y-1]=count;
         printf("%d\n",count);
	     for(int i=0;i<M;i++)
            for(int j=0;j<N;j++)
                if(visit[i][j])cost[i][j]=count;
	   }
       else printf("%d\n",cost[x-1][y-1]);
      }

   }
 return 0;
}
