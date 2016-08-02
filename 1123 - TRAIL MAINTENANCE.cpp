
//BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopner soman boro
 Author :: Shakil Ahmed
.............AUST_CSE27.........
 prob   ::
 Type   ::
 verdict::
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>
#include <set>
#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <list>
#include <map>
#include <queue>
#include <sstream>
#include <utility>
#define pf(a) printf("%d\n",a)
#define pf2(a,b) printf("%d %d\n",a,b)
#define pfcs(cs,a) printf("Case %d: %d\n",cs,a)
#define sc(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
#define pi acos(-1.0)
#define ff first
#define LL long long
#define ss second
#define rep(i,n) for(i = 0; i < n; i++)
#define REP(i,n) for(i=n;i>=0;i--)
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define ROF(i,a,b) for(int i = a; i >= b; i--)
#define re return
#define QI queue<int>
#define SI stack<int>
#define pii pair <int,int>
#define MAX
#define MOD
#define INF 1<<30
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define memo(a,b) memset((a),(b),sizeof(a))
#define G() getchar()


using namespace std;


template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
struct edge
{
       int u,v,c;
}in[6000+5],mst[(6000+5)];
int matrix[205][205],par[205],rank[205];
bool vis[205];
vector <int> adj[205];
void make_pair(int x)
{
       par[x]=x;
       rank[x]=0;
       adj[x].clear();
}
int find_parent(int x)
{
       if(x!=par[x])
       par[x]=find_parent(par[x]);
       return par[x];
}
bool cmp(edge a,edge b)
{
       return a.c<b.c;
}

void link(int a,int b)
{
       if(rank[a]>rank[b])
       {
              par[b]=a;
       }
       else
       {
              par[a]=b;
              if(rank[a]==rank[b]) rank[b]++;
       }
}
void make_union(int a,int b)
{
       link(a,b);
}
int main()
{

    //freopen("in.txt", "r", stdin);
    int cs,T;
    sc(T);
   // printf("sc:: %d\n",T);
    FOR(cs,1,T)
    {      int n,m,i,idx=0,ct,ans,mx=INF,mst_c=0,j;
           printf("Case %d:\n",cs);
           cin>>n>>m;
           rep(i,m)
           {
                  scanf("%d %d %d",&in[idx].u,&in[idx].v,&in[idx].c);
                  idx++;
                  if(idx<n-1)
                  {
                         puts("-1");
                         continue;
                  }
                  mst_c=0;
                  ct=0;
                  sort(in,in+idx,cmp);
                  FOR(j,1,n) make_pair(j);
                  for(j=0;j<idx && ct!=n-1;j++)
                  {
                         int nu=find_parent(in[j].u);
                         int nv=find_parent(in[j].v);
                         if(nu!=nv)
                         {
                                in[ct++]=in[j];
                                make_union(nu,nv);
                                mst_c+=in[j].c;
                         }
                  }
                  idx=ct;
                  if(ct!=n-1) printf("-1\n");
                  else
                  {
                         printf("%d\n",mst_c);
                  }


           }


    }



}
