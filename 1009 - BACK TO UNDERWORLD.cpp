
//BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopenr soman boro
 Author :: Shakil Ahmed
 prob   :: light oj 1009
 Type   :: dfs,bicolor
 verdict::
 */
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <set>
#include <vector>
#define MAX 20005
using namespace std;
int prev=0;
vector <int> adj[MAX];
int visit[MAX],color[2];
void ini()
{
    int i;
    for(i=0; i<MAX; i++)
    {
        adj[i].clear();
        visit[i]=0;
    }
}
void dfs(int node,int c)
{
    int i;
    visit[node]=1;
    color[c]++;
    for(i=0; i<adj[node].size(); i++)
        if(!visit[adj[node][i]]) dfs(adj[node][i],(c+1)%2);
}
int main()
{
  //  freopen("input.txt","r",stdin);
    int nd,edg,cs=1;
    scanf("%d",&nd);
    while(nd--)
    {
        ini();
        set<int> s;
        s.clear();
        set<int> :: iterator it;
        int u,v,i;
        scanf("%d",&edg);
        while(edg--)
        {
            scanf("%d %d",&u,&v);
            adj[u].push_back(v);
            adj[v].push_back(u);
            s.insert(u);
            s.insert(v);
        }
        color[0]=color[1]=0;
        int res=0;
        for(it=s.begin(); it!=s.end(); it++)
            if(!visit[*it])
            {  color[0]=color[1]=0;
               memset(visit,0,sizeof(0));
               dfs(*it,0);
               int ret=max(color[0],color[1]);
               memset(visit,0,sizeof(0));
               color[0]=color[1]=0;
               dfs(*it,1);
               ret=max(ret,max(color[0],color[1]));
               res+=ret;

            }
          //for(it=s.begin(); it!=s.end(); it++)
          //printf("node :: %d  color::%d\n",*it,color[*it]);
         // printf("Color[0]:: %d color[1]:: %d\n",color[0],color[1]);
        printf("Case %d: %d\n",cs++,res);


    }
}
