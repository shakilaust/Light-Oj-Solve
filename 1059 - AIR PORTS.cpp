
//BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopenr soman boro
 Author :: Shakil Ahmed
 prob   :: uva 11733
 Type   :: MST
 verdict:: YES
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
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
#define pf printf
#define sc scanf
#define pb push_back
#define mp make_pair
#define pi acos(-1.0)
#define LL long long
#define ff first
#define ss second
#define rep(i,n) for(int i = 0; i < n; i++)
#define REP(i,n) for(int i=n;i>=0;i--)
#define ROF(i,a,b) for(int i = a; i <= b; i++)
#define rof(i,a,b) for(int i = a; i >= b; i--)
#define re return
#define QI queue<int>
#define SI stack<int>
#define pii pair <int,int>
#define MAX 10000
#define INF 1<<29
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))

using namespace std;

template<class T> T abs(T x) {re x > 0 ? x : -x;}
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }

struct graph
{
    int u,v,c;

}in[(MAX*10)+5];
bool comp( graph a, graph b ){
    return a.c<b.c;
}
int par[MAX+5],rank[MAX+5],nV,nE,MA;
void make_set(int x)
{
    par[x]=x;
    rank[x]=0;
}
int find_set(int x)
{
    if(x!=par[x])
    par[x]=find_set(par[x]);
    return par[x];
}
void link(int x,int y)
{
    if(rank[x]>rank[y])
    {
        par[y]=x;
    }
    else
    {
        par[x]=y;
        if(rank[x]==rank[y])  // main node er rank sob somoy boro hobe
        rank[y]++;
    }
}
void Union(int x,int y)
{
    link(find_set(x),find_set(y));
}


LL MST()
{
    LL mst_c=0,i,_u,_v;
    for(i=1;i<=nV;i++)
    make_set(i);
    sort(in,in+nE,comp);
    for(i=0;i<nE;i++)
    {
        _u=in[i].u;
        _v=in[i].v;
        if(find_set(_u)!=find_set(_v) && in[i].c < MA )
        {
            mst_c+=in[i].c;
            Union(find_set(_u),find_set(_v));
        }
    }
    return mst_c;
}
void input()
{   int i;
    scanf("%d %d %d",&nV,&nE,&MA);
    for(i=0;i<nE;i++)
    scanf("%d %d %d",&in[i].u,&in[i].v,&in[i].c);
}
int main()
{    //freopen("input.txt","r",stdin);
    int t,i,cs;
    scanf("%d",&t);
    for(cs=1;cs<=t;cs++)
    {   set <int> S;
        S.clear();
        input();
        LL res=MST();
        for(i=1;i<=nV;i++)
        {S.insert(find_set(i));
        //printf("i :: %d par:: %d\n",i,find_set(i));
        }
        //printf("MA:: %d  res:: %lld\n",MA,res);
        printf("Case %d: %lld %d\n",cs,((MA*S.size())+res),S.size());

    }
}

