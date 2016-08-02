
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
struct abc
{
       int in[10];
       int num;
}now,prev;
int start[10],idx;
bool prime[]={0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1};

bool distination(int a[])
{
       int i;
       for(i=1;i<8;i++)
       {
              if(abs(a[i-1])>abs(a[i])) return false;
       }
       return true;
}
int trie[10000][10];
void insert(int a[])
{
       int cur=0,i;
       for(i=0;i<8;i++)
       {
              int j=abs(a[i]);
              if(trie[cur][j]==-1)
              {
                     trie[cur][j]=++idx;
                     memset(trie[idx],-1,sizeof(trie[idx]));
              }
              cur=trie[cur][j];
       }
}
bool ok(int a[])
{
       int cur=0,i;
       for(i=0;i<8;i++)
       {
              int j=abs(a[i]);
              if(trie[cur][j]==-1) // new entry so true;
              return true;
              cur=trie[cur][j];

       }
       return false;
}

int bfs()
{       queue<abc> q;
        memset(trie[0],-1,sizeof(trie[0]));
        int i,j;
        for(i=0;i<8;i++) now.in[i]=start[i];
        now.num=0;
        q.push(now);
        insert(now.in);
        if(distination(now.in))
               {
                      return 0;
               }
               int ct=0;
        while(!q.empty())
        {
               prev=q.front();
               q.pop();
               ct++;
               if(ct>=100000) break;

               for(i=0;i<8;i++)
               {
                      for(j=i+1;j<8;j++)
                      {      if(i==j) continue;
                             int num1=prev.in[i];
                             int num2=prev.in[j];
                             if(num1*num2<0 && prime[abs(num1)+abs(num2)])
                             {     //  i,j idx eksathe hobe
                                    now=prev;
                                    int k;
                                      if(abs(num1)>abs(num2))
                                           {
                                                  for(k=i;k<=j-1;k++)
                                                  now.in[k]=prev.in[k+1];
                                                  now.in[j]=prev.in[i];
                                           }
                                           else
                                           {
                                                  for(k=i;k<=j-2;k++)
                                                  now.in[k]=prev.in[k+1];
                                                  now.in[j-1]=prev.in[i];
                                           }
                                             //  printf("before ::: ");
                                                 // for(k=0;k<8;k++) printf(" %d",now.in[k]);
                                                 //  printf("\n");
                                           if(ok(now.in))
                                           {
                                                  insert(now.in);
                                                  //printf("after ::: ");
                                                 // for(k=0;k<8;k++) printf(" %d",now.in[k]);
                                                 //  printf("\n");
                                                  now.num=prev.num+1;
                                                 if(distination(now.in))
                                                 return now.num;
                                                  q.push(now);
                                           }
                                //j,i,idx eksathe hobe
                                    now=prev;
                                            if(abs(num1)>abs(num2))
                                           {
                                                  for(k=i+1;k<=j;k++)
                                                  now.in[k]=prev.in[k-1];
                                                  now.in[i]=prev.in[j];
                                           }
                                           else
                                           {

                                                  for(k=i+2;k<=j;k++)
                                                  now.in[k]=prev.in[k-1];
                                                  now.in[i+1]=prev.in[j];

                                           }
                                     if(ok(now.in))
                                           {
                                                 insert(now.in);
                                                  now.num=prev.num+1;
                                                 if(distination(now.in))
                                                 return now.num;

                                                // printf("\n");

                                                  q.push(now);
                                           }

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
    scanf("%d",&t);
    for(cs=1;cs<=t;cs++)
    {
           int i;
       for(i=0;i<8;i++)
       {
              scanf("%d",&start[i]);
       }
       printf("Case %d: %d\n",cs,bfs());
    }
}

/*
1
2 -8 -4 5 6 7 3 -1
*/
