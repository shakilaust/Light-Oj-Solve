
//BISMILLAHIRRAHMANIRRAHIM
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#define MAX 10000
using namespace std;
int n,discovery[MAX+5],back[MAX+5],pred[MAX+5],color[MAX+5],time;
struct edge
{
    int x,y;
} in[10000+5],g;
vector <int> G[MAX+3];
vector <edge> articulation_point;
void ini()
{
    int i;
    for(i=0; i<=MAX; i++)
    {
        G[i].clear();
    }
    memset(color,0,sizeof(color));
     memset(back,0,sizeof(back));
      memset(discovery,0,sizeof(discovery));
      memset(pred,0,sizeof(pred));
    articulation_point.clear();
    time=0;
}

void input()
{
    int i,j;
    scanf("%d",&n);
  //  printf("n::%d\n",n);
    ini();
    for(i=0; i<n; i++)
    {
        int node,t,w;
        scanf("%d (%d)",&node,&t);
        //printf("node::%d  t::%d\n",node,t);
        for(j=0; j<t; j++)
        {
            scanf("%d",&w);
            G[node].push_back(w);
            G[w].push_back(node);
        }
    }

}
bool cmp(edge a,edge b)
{
    if(a.x==b.x)  return a.y<b.y;
    return a.x<b.x;
}

void Arti(int u)
{
    color[u]=1;
    discovery[u]=back[u]=++time;
  //  printf("u:: %d  dis:: %d back::%d\n",u,discovery[u],back[u]);
    int i,child=0;
    for(i=0; i<G[u].size(); i++)
    {
        int v=G[u][i];
        if(!color[v])
        {
            pred[v]=u;
            Arti(v);
            if(discovery[u]==1)
            {
                if(G[u].size()>=2 && back[v]>discovery[u])
                {
                    if(u<v)
                    {
                        g.x=u;
                        g.y=v;
                    }
                    else
                    {
                        g.x=v;
                        g.y=u;
                    }
                    articulation_point.push_back(g);

                }
            }
            else if(back[v]>discovery[u])
            {
                if(u<v)
                {
                    g.x=u;
                    g.y=v;
                }
                else
                {
                    g.x=v;
                    g.y=u;
                }
                articulation_point.push_back(g);
            }
            back[u]=min(back[u],back[v]);
        }
        else if(v!=pred[u])
        {
            back[u]=min(back[u],discovery[v]);
        }

    }
}
void dfs()
{
    int i;

    for(i=0; i<n; i++)  {if(!color[i]) Arti(i); }
}
int main()
{   //freopen("input.txt","r",stdin);
    int cs,t,i;
    scanf("%d",&t);
    getchar();
    for(cs=1; cs<=t; cs++)
    {
        input();
        dfs();
        sort(articulation_point.begin(),articulation_point.end(),cmp);
        int sz=articulation_point.size();
        printf("Case %d:\n%d critical links\n",cs,sz);
        for(i=0; i<sz; i++)
        {
            printf("%d - %d\n",articulation_point[i].x,articulation_point[i].y);
        }

    }
}
