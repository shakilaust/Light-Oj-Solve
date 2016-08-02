
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
#define MOD 1000000007
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
const int N=100005;
LL tree[N];
int maxVal,a[N];
void write(int idx,LL val)
{
       while(idx<maxVal)
       {      tree[idx]=(tree[idx]+val)%MOD;
              idx+=(idx & -idx);
       }
}
LL read(int idx)
{
       LL sum=0;
       while(idx>0)
       {
              sum+=tree[idx];
              sum%=MOD;
              idx-=(idx & -idx);
       }
       return sum;
}

int main()
{

    //freopen("in.txt", "r", stdin);
    int cs,t;
    scanf("%d",&t);
    for(cs=1;cs<=t;cs++)
    {
           set <int> s;
           map <int,int> m;
           int idx,i,n;
           scanf("%d",&n);
           for(i=0;i<n;i++)
           {
                  scanf("%d",&a[i]);
                  s.insert(a[i]);
           }
           set <int> :: iterator it;
           for(idx=1,it=s.begin();it!=s.end();it++,idx++)
           m[*it]=idx;
           maxVal=s.size()+1;
           LL ans=0;
           for(i=0;i<=maxVal;i++) tree[i]=0;
           for(i=0;i<n;i++)
           {
                  LL val=read(m[a[i]]-1)+1;
                  ans=(ans+val)%MOD;
                  write(m[a[i]],val);
           }
           printf("Case %d: %d\n",cs,ans);
    }



}
