
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
#define MAX 100005
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
long long int tree[(MAX<<2)],Lazy[(MAX<<2)];
void propagete(int lf,int rt,int idx)
{
       int mid=(lf+rt)/2;
       long long int prev=Lazy[idx];
       Lazy[2*idx]+=prev;
       Lazy[(2*idx)+1]+=prev;
       tree[(2*idx)]+=(mid-lf+1)*prev;
       tree[(2*idx)+1]+=(rt-mid)*prev;
       tree[idx]=tree[(2*idx)]+tree[(2*idx)+1];
       Lazy[idx]=0;
}

void update(int lf,int rt,int idx,int x,int y,int val)
{
        if(lf>=x && rt<=y)
       {
              Lazy[idx]+=val;
              tree[idx]+=(rt-lf+1)*val;
              return ;
       }
       int mid=(lf+rt)/2;
       if(Lazy[idx]) propagete(lf,rt,idx);
       if(x<=mid)
       update(lf,mid,2*idx,x,y,val);
       if(y>mid)
       update(mid+1,rt,2*idx+1,x,y,val);
       tree[idx]=tree[(2*idx)]+tree[(2*idx)+1];
}
long long int query(int lf,int rt,int idx,int x,int y)
{
       if(lf>=x && rt<=y) return tree[idx];
       if(Lazy[idx]) propagete(lf,rt,idx);
       long long int ret=0;
       int mid=(lf+rt)/2;
       if(x<=mid)
       ret+=query(lf,mid,2*idx,x,y);
       if(y>mid)
       ret+=query(mid+1,rt,2*idx+1,x,y);
       return ret;
}
int main()
{

    //freopen("in.txt", "r", stdin);
    int cs,t;
    scanf("%d",&t);
    for(cs=1;cs<=t;cs++)
    {
           int n,q;
           memo(tree,0);
           memo(Lazy,0);
           scanf("%d %d",&n,&q);
           printf("Case %d:\n",cs);
           while(q--)
           {
                  int x,y,val,op;
                  scanf("%d",&op);
                  if(!op)
                  {
                         scanf("%d %d %d",&x,&y,&val);
                         update(0,n-1,1,x,y,val);
                  }
                  else
                  {
                         scanf("%d %d",&x,&y);
                         printf("%lld\n",query(0,n-1,1,x,y));
                  }
           }
    }



}
