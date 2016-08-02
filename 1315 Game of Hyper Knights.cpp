
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
template <class T> inline T bigmod(T p,T e,T M)
{
    if(e==0)return 1;
    if(e%2==0){LL t=bigmod(p,e/2,M);return (T)((t*t)%M);}
    return (T)((LL)bigmod(p,e-1,M)*(LL)p)%M;
}

template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}
//Fast Reader
template<class T>inline bool read(T &x){int c=getchar();int sgn=1;while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}for(x=0;~c&&'0'<=c&&c<='9';c=getchar())x=x*10+c-'0'; x*=sgn; return ~c;}

/* **************************************  My code start here ****************************************** */
const int maxn = 505;
int dr[] = {-2,-3,-2,-1,-1,1};
int dc[] = {1,-1,-1,-2,-3,-2};
int Grandy[maxn][maxn];
bool ok(int x , int y)
{
    if( x <0 || y < 0 || x >= 505 || y >= 505 ) return 0;
    return 1;
}
int Cal(int x , int y)
{
    if(x == 0 && y <= 0 ) return 0 ;
    int &ret = Grandy[x][y];
    if(ret!=-1) return ret;
    int k , ans = 0 , i;
    set <int> s;
    for ( i = 0 ; i < 6 ; i++ )
    {
        int nx = x + dr[i];
        int ny = y + dc[i];
        if(ok(nx,ny))
        {
            s.insert(Cal(nx,ny));
        }
    }
    while(s.find(ans)!=s.end()) ans++;
    return ret = ans;
}
int main()
{
  // freopen("input.txt","r",stdin);
     //freopen("output.txt","w",stdout);
     int cs , t ;
     read(t);
     memo(Grandy,-1);
     for ( cs = 1 ; cs <= t ; cs++ )
     {
         int n , i , x , y , ans = 0 ;
         read(n);
         rep(i,n)
         {
             read(x) , read(y);
             ans ^= Cal(x,y);

         }
         printf("Case %d: ",cs);
         if(ans) puts("Alice");
         else puts("Bob");
     }
   return 0;
}
