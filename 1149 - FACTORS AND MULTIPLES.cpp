
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
#define MAX 105
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

int Left[MAX],Right[MAX],adj[MAX][MAX],A[MAX],seen[MAX],deg[MAX],B[MAX],n,m;
bool bmp(int u)
{
       for(int i=0,v;i<deg[u];++i)
       {
              v=adj[u][i];
              if(seen[v]) continue;
              seen[v]=1;
              if(Right[v]==-1 || bmp(Right[v]))
              {
                     Right[v]=u;
                     Left[u]=v;
                     return true;
              }
       }
       return false;
}
int bipertilematching()
{
       memo(Left,-1);
       memo(Right,-1);
       int cnt=0,i;
       for(i=0;i<m;i++)
       {
              memo(seen,0);
              if(bmp(i)) {  cnt++;  }
       }
    return cnt;
}
int main()
{

    //freopen("in.txt", "r", stdin);
    int i,j,cs,t;
    scanf("%d",&t);
    FOR(cs,1,t)
    {
           scanf("%d",&n);
           rep(i,n) scanf("%d",&A[i]);
           scanf("%d",&m);
           rep(i,m) scanf("%d",&B[i]);
           memo(deg,0);
           rep(i,n) rep(j,m)
           {
                  if(B[j]%A[i]==0)
                  {
                         adj[j][deg[j]++]=i;
                  }
           }
           printf("Case %d: %d\n",cs,bipertilematching());
    }



}
