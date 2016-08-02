
//BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopner soman boro
 Author :: Shakil Ahmed
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
#define sc(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
#define pi acos(-1.0)
#define LL long long
#define long long int64
#define ff first
#define ss second
#define rep(i,n) for(i = 0; i < n; i++)
#define REP(i,n) for(i=n;i>=0;i--)
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define ROF(i,a,b) for(int i = a; i >= b; i--)
#define re return
#define QI queue<int>
#define SI stack<int>
#define pii pair <int,int>
#define MAX 1000000
#define INF 1<<29
#define SZ(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define memo(a,b) memset((a),(b),sizeof(a))
#define G() getchar()


using namespace std;

const int NN = 1005;


template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }

int money[NN];
bool vis[NN];
vector <int> adj [NN];
int cnt,cost,avg;
void dfs( int u ) {
    if( vis[u] ) return;
    vis[u] = true;
    cnt++;
    cost += money[u];
    int i;
    rep(i,SZ(adj[u])) if(!vis[adj[u][i]]) dfs(adj[u][i]);
}



int main()
{

    //freopen("in.txt", "r", stdin);
    int cs,t;
    cin>>t;
    FOR(cs,1,t)
    {
           int n,m,total=0,i;
           cin>>n>>m;
           rep(i,n)
           {
                  cin>>money[i];
                  total+=money[i];
                  adj[i].clear();
           }
           while(m--)
           {
                  int u,v;
                  cin>>u>>v;
                  u--,v--;
                  adj[u].pb(v);
                  adj[v].pb(u);
           }
           printf("Case %d: ",cs);
           bool flag=true;
           avg=total/n;
           if(total%n)
           {
                  flag=false;
           }
           else
           {      memo(vis,0);
                  rep(i,n)
                  {
                         cnt=cost=0;
                         if(!vis[i])
                         {
                                dfs(i);
                                if(cnt * avg !=cost)
                                {
                                       flag=false;
                                       break;
                                }
                         }
                  }
           }
             printf("%s\n", flag ? "Yes" : "No");

    }
}
