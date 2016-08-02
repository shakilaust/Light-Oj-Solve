#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
char maze[22][22];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int count,row,col;
void dfs(int x,int y)
{  maze[x][y]='#';
   for(int i=0;i<4;i++)
   { int nx=dx[i]+x;
     int ny=dy[i]+y;
    if(nx>=0 && ny>=0 && nx<row && ny<col && maze[nx][ny]=='.') { dfs(nx,ny);count++;}
   }
}

int main()
{  int T;
   cin>>T;
   for(int tt=1;tt<=T;tt++)
   {  count=1;
      cin>>col>>row;
      for(int i=0;i<row;i++) scanf("%s",maze[i]);
      for(int i=0;i<row;i++)
	      for(int j=0;j<col;j++) if(maze[i][j]=='@') dfs(i,j);
      printf("Case %d: %d\n",tt,count);
   }
 return 0;
}
