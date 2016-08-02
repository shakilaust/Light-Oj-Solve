
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
#define MAX3(a,b,c) max(a,max(b,c))

double const EPS=3e-8;
using namespace std;


template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
bool vis[30][30][30];
int Value(char c)
{
       return c-'a';
}
void ini()
{      memo(vis,0);
       int n,i,j,k,idx1,idx2,idx3,x;
       string a,b,c;
       scanf("%d",&n);
       for(x=1;x<=n;x++)
       {
       cin>>a>>b>>c;
       for(i=0;i<a.size();i++)
       {      idx1=Value(a[i]);
              for(j=0;j<b.size();j++)
                 {      idx2=Value(b[j]);
                        for(k=0;k<c.size();k++)
                        {    idx3=Value(c[k]);
                              vis[idx1][idx2][idx3]=1;

                        }
                 }
       }
       }
}
char change(char c,int n)
{
       if(!n)
       {
              if(c=='z') return 'a';
              else return c+1;
       }
       else
       {
              if(c=='a') return 'z';
              else return c-1;
       }
}
struct abc
{
       string s;
       int c;
}in,prev,cur;
string start,end;

int bfs()
{      queue<abc> q;
       in.s=start;
       in.c=0;
       q.push(in);
       int  idx1=Value(in.s[0]);
       int idx2=Value(in.s[1]);
       int idx3=Value(in.s[2]);
       if(vis[idx1][idx2][idx3]) return -1;
       else vis[idx1][idx2][idx3]=1;
       while(!q.empty())
       {
              prev=q.front();
              q.pop();
              if(prev.s==end)
              {
                     return prev.c;
              }
              int i,j;
              for(i=0;i<3;i++)
              {
                     for(j=0;j<2;j++)
                     {
                            cur=prev;
                            cur.s[i]=change(cur.s[i],j);
                             idx1=Value(cur.s[0]);
                             idx2=Value(cur.s[1]);
                             idx3=Value(cur.s[2]);
                            if(!vis[idx1][idx2][idx3]){
                                   vis[idx1][idx2][idx3]=1;
                                   cur.c=prev.c+1;
                                   q.push(cur);
                            }
                     }
              }
       }
       return -1;
}

int main()
{

    //freopen("in.txt", "r", stdin);
    int cs,t;
    sc(t);
    rep(cs,t)
    {
           cin>>start>>end;
           ini();
           printf("Case %d: %d\n",cs+1,bfs());
    }



}
