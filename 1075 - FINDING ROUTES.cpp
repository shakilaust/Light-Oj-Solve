
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
#define INF 1LL<<31-1
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define memo(a,b) memset((a),(b),sizeof(a))
#define G() getchar()


using namespace std;


template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
vector <int> adj[500];
bool vis[500];
 map <string,int> mymap,asekotobar;
 map <int,string> res;
void dfs(int u)
{
       cout<<res[u]<<endl;
       vis[u]=1;
       int i,sz=adj[u].size();
       rep(i,sz) if(vis[adj[u][i]]==0) dfs(adj[u][i]);

}



int main()
{

   // freopen("in.txt", "r", stdin);
    int cs,T;
    sc(T);
    FOR(cs,1,T)
    {     // if(cs!=1) puts("");
           int n,i,ct=1;
           string a,b;
            memo(vis,0);
            mymap.clear();
            asekotobar.clear();
            res.clear();
            for(i=0;i<500;i++) adj[i].clear();
           map <string,int> :: iterator it;
           sc(n);
           n--;
           rep(i,n)
           {
                  cin>>a>>b;
                  asekotobar[a]++;
                  asekotobar[b]--;
                  if(!mymap[a]) mymap[a]=ct++;
                  res[mymap[a]]=a;
                  if(!mymap[b]) mymap[b]=ct++;
                  res[mymap[b]]=b;
                  adj[mymap[a]].pb(mymap[b]);
           }
           printf("Case %d:\n",cs);
           for(it=asekotobar.begin();it!=asekotobar.end();it++)
              if(it->second==1)
              {
                     dfs(mymap[it->first]);
                     break;
              }
              puts("");


    }


}
