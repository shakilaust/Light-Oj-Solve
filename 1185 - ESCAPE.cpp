

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
vector <int> adj[105];
int color[105][3];
void dfs(int u,int col)
{      if(col!=-1)
       color[u][col]=1;
       int nextcol=1;
       if(col==1) nextcol=2;
       int i;
       for(i=0;i<adj[u].size();++i)
       {
              if(!color[adj[u][i]][nextcol]) dfs(adj[u][i],nextcol);
       }
}

int main()
{

    //freopen("in.txt", "r", stdin);
    int cs,T;
    sc(T);
    FOR(cs,1,T)
    {
           int n,m,u,v,i,one=0,two=0,ct=0,j;
           cin>>n>>m;
            FOR(i,1,n) adj[i].clear();
           rep(i,m)
           {
                  cin>>u>>v;
                  adj[u].pb(v);
                  adj[v].pb(u);
           }
           bool check=true;
           memo(color,0);
           dfs(1,-1);

           ct=0;
           FOR(i,1,n)  if(color[i][2]==1) ct++;
           printf("Case %d: %d\n",cs,ct);

    }


}
