
#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
#define LL long long int
using namespace std;
struct abc
{
    int u,v,w;
}in;
bool cmp(abc a,abc b)
{
    return a.w<b.w;
}
vector <abc> G;
int par[105],rank[105],n;
void make_parent(int x)
{
    par[x]=x;
    rank[x]=0;
}
int find_parent(int x)
{
    if(x==par[x]) return x;
    else return par[x]=find_parent(par[x]);
}
void Union(int x,int y)
{
    if(rank[x]>rank[y])
    {
        par[y]=par[x];
    }
    else
    {
        par[x]=par[y];
        if(rank[x]==rank[y])
        {
            rank[y]++;
        }
    }
}
LL MST_BEST()
{   int i,j,k,sz=G.size(),ct=0,p,q;
    LL mst_c=0;
    for(i=0;i<=n;i++)
    make_parent(i);
    sort(G.begin(),G.end(),cmp);
    for(i=0;i<sz && ct<n;i++)
    {
        p=find_parent(G[i].u);
        q=find_parent(G[i].v);
        if(p!=q)
        {
            mst_c+=G[i].w;
            Union(p,q);
            ct++;
        }
    }

    return mst_c;
}
LL MST_WORST()
{
     int i,j,k,sz=G.size(),ct=0,p,q;
    LL mst_c=0;
    for(i=0;i<=n;i++)
    make_parent(i);
    for(i=sz-1;i>=0 && ct<n;i--)
    {
        p=find_parent(G[i].u);
        q=find_parent(G[i].v);
        if(p!=q)
        {
            mst_c+=G[i].w;
            Union(p,q);
            ct++;
        }
    }

    return mst_c;
}
int main()
{
   // freopen("input.txt","r",stdin);
    int t,kase=1;
    for(scanf("%d",&t);kase<=t;kase++)
    {   G.clear();
        scanf("%d",&n);

        while(1)
        {
            scanf("%d %d %d",&in.u,&in.v,&in.w);
            if(!in.u && !in.v &&  !in.w)  break;

            G.push_back(in);
        }
        LL Res_best=MST_BEST();
        LL Res_worst=MST_WORST();
        if((Res_best+Res_worst) %2 )
        printf("Case %d: %lld/2\n",kase,(Res_best+Res_worst));
        else
        printf("Case %d: %lld\n",kase,(Res_best+Res_worst)/2);


    }

}
