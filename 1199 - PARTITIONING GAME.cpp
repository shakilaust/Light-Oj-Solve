
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
int grundy[10000+5];
void pre()
{
       int i,j,k;
       grundy[1]=grundy[2]=0;
       set<int> s;
       for(i=3;i<=10000;i++)
       {      s.clear();
              if(i%2)
              k=(i/2)+1;
              else k=(i/2);
              for(j=1;j<k;j++)
              {
                     s.insert(grundy[j]^grundy[i-j]);
              }
              int ret=0;
              while(s.find(ret)!=s.end()) ret++;
              grundy[i]=ret;
       }
}


int main()
{

    //freopen("in.txt", "r", stdin);
    pre();
    int cs,T;
    sc(T);
    FOR(cs,1,T)
    {
           int res=0,n,i,in;
           cin>>n;
           rep(i,n)
           {
                  cin>>in;
                  res^=grundy[in];
           }
           if(res) printf("Case %d: Alice\n",cs);
           else printf("Case %d: Bob\n",cs);
    }



}
