
using namespace std;

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include <set>

#define min(a,b) ((a<b)?(a):(b))

vector<int>graph[10000+10];
int back[10000+10],discovery[10000+10],cnt,seq;//,child[10000+10];
bool visited[10000+10],art_point[10000+10];
set <int> ans;

void dfs(int u)
{
        int child=0;
        visited[u]=true;
        back[u]=discovery[u]=++seq;

        for(int i=0;i<graph[u].size();i++)
        {
                int v = graph[u][i];
                if(visited[v]==false)
                {
                        dfs(v);
                        child++;
                        back[u]=min(back[u],back[v]);
                       if(discovery[u]>1 && back[v]>=discovery[u])
                                        ans.insert(u);//cnt++;

                }
                else if(discovery[v]<discovery[u]-1) // back edge
                        back[u]=min(discovery[v],back[u]);
        }
          if(discovery[u]==1  && child>=2)
                                    ans.insert(u);//cnt++;

}

int main()
{
        int t,n,m,i,u,v,Case=1;
        scanf("%d",&t);

        while(t--)
        {
                scanf("%d%d",&n,&m);

                for(i=0;i<=n;i++)
                {
                        art_point[i]=visited[i]=false;
                        graph[i].clear();
                        //child[i]=0;
                }

                while(m--)
                {
                        scanf("%d%d",&u,&v);
                        graph[u].push_back(v);
                        graph[v].push_back(u);
                }

                seq=cnt=0;
                ans.clear();
                dfs(1);


                printf("Case %d: %d\n",Case++,ans.size());

        }

        return 0;
}
