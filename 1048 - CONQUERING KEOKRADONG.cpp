
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
int n,k,in[1005];

bool possible(int mid)
{
       int cnt=0,i,cur=0;
       for(i=0;i<n;i++)
       {
              cur+=in[i];
              if(cur>mid)
              {
                     cnt++;
                     cur=in[i];
              }

       }
      // printf("mid:: %d cnt:: %d   bool::%d\n",mid,cnt,cnt<=k);
       cnt++;
       return cnt<=k;

}

int main()
{

    //freopen("in.txt", "r", stdin);
    int cs,t;
    sc(t);
    FOR(cs,1,t)
    {
           int high=0,low=-1,i;
           scanf("%d %d",&n,&k);
           n++,k++;
         //  printf("n:: %d k::%d\n",n,k);
           for(i=0;i<n;i++)
           {
                  scanf("%d",&in[i]);
                  high+=in[i];
                  if(in[i]>low) low=in[i];
           }
           int res=low;
           while(low<high)
           {
                  int mid=(low+high)/2;
                  if(possible(mid))
                  {
                         res=mid;
                         high=mid;
                  }
                  else low=mid+1;
           }
           printf("Case %d: %d\n",cs,res);
           int cnt=k,cur=0;

           for(i=0;i<n;i++)
           {
                   cur+=in[i];
              if(cur>res || n-i+1==cnt)
              {
                     cnt--;
                     cur-=in[i];
                     printf("%d\n",cur);
                     cur=in[i];
              }

           }
           printf("%d\n",cur);


    }



}
