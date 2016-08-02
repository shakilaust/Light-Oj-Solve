
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
}in[(50*50)+5];
int rank[55],par[55];
bool cmp(edge a,edge b)
{
       return a.c<b.c;
}
void make_par(int x)
{
       par[x]=x;
       rank[x]=0;
}
int find_parent(int x)
{
       if(x!=par[x])
       par[x]=find_parent(par[x]);
       return par[x];
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
    FOR(cs,1,T)
    {
           int n,i,j,idx=0,sum=0,x=0,ct=1,cost=0;
           bool flag=true;
           map <string,int> m;
           sc(n);
           for(i=1;i<=n;i++) {

                     string a,b;
                     cin>>a>>b>>j;
                     if(!m[a]) m[a]=++x;
                     if(!m[b]) m[b]=++x;
                            in[idx].u=m[a];
                            in[idx].v=m[b];
                            in[idx++].c=j;

           }
           sort(in,in+idx,cmp);
           for(i=1;i<=x;i++) make_par(i);
           for(i=0;i<idx;i++)
           {
                  int nu=find_parent(in[i].u);
                  int nv=find_parent(in[i].v);
                  if(nu!=nv)
                  {      ct++;
                         make_union(nu,nv);
                         cost+=in[i].c;

                  }
           }
           if(ct<x) printf("Case %d: Impossible\n",cs);
           else{
                   printf("Case %d: %d\n",cs,cost);
           }

    }



}
