
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 105
#define INF 2147483647

using namespace std;
int capacity[MAX][MAX],from[MAX];
int source,sink,next,where,prev,edge,kase;
int BFS(int node)
{
    int i,cost;
    for(i=1;i<=node;i++)
    from[i]=-1; //color it as unvisited
    queue <int> q;
    q.push(source);
    from[source]=-2; // its a unique visited term just for source
    while(!q.empty())
    {
        where=q.front();
        q.pop();
        if(where==sink) // ami destination e chole assi
        {
            // ekhon ami sob ceye kom cost er noder berkorbo, tai hobe amar currecnt flow
            cost=INF;
            where=sink;
            while(from[where]!=-2)
            //unique visited term for source, thats always perfrom to reach source
            {
                prev=from[where];
                if(cost>capacity[prev][where]) // kotha theke aslam
                cost=capacity[prev][where]; //update until the minimum one
                where=prev;
            }
            return cost;
        }
        for(i=1;i<=node;i++)
        {
            if(capacity[where][i]!=0 && from[i]==-1)
            {   q.push(i);
                from[i]=where;
            }
        }
    }
    return 0;
}
int MaxFlow(int node)
{
    int total=0,cf=0;
    while((cf=BFS(node))!=0)
    {
        total+=cf;
        where=sink;
        //update residual network
        while(from[where]!=-2)
        {
            prev=from[where];
            capacity[prev][where]-=cf;
            capacity[where][prev]+=cf;
            where=prev;
        }
    }
    return total;
}
void ini(int node)
{
    int i,j;
    for(i=1;i<=node;i++)
       for(j=1;j<=node;j++)
          capacity[i][j]=0;

}
void input()
{   int u,v,w,i;
    scanf("%d %d %d",&source,&sink,&edge);
    for(i=1;i<=edge;i++)
    {
        scanf("%d %d %d",&u,&v,&w);
        capacity[u][v]=capacity[v][u]+=w;
    }
}

void solve()
{   int node;
    scanf("%d",&node);
    ini(node);
    input();
    int result=MaxFlow(node);
    printf("Case %d: %d\n",kase,result);
}
int main()
{  // freopen("input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(kase=1;kase<=t;kase++)
    {
       // printf("Case %d: ",kase);
        solve();
    }
}
