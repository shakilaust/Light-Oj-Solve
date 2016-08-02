
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
const int MAXN = 1e5 + 5 ;
bool check[MAXN] ;
LL prime[MAXN] , idx = 0 ;
vector < pair<LL ,LL> > prime_fact[4];
bool has[4][MAXN];
LL mx  ;
void seive()
{
    int i , j ;
    prime[idx++] = 2;
    for( i = 3 ; i*i <MAXN ; i+=2)
    {
        if(check[i]==0)
        {   prime[idx++] = i ;
            for ( j = i*i ; j <= MAXN ; j+= (2*i)) check[j] = 1;
        }
    }
    while(i<MAXN)
    {
        if(check[i]==0 ) prime[idx++] = i ;
        i+=2;
    }
}

int main()
{
    seive();
    int cs , t ;
    read(t);
    FOR(cs , 1 , t )
    {
        LL a , b , L ;
        read(a) , read(b) , read(L);
        printf("Case %d: ",cs);
        //LL d = lcm(a,b);
        if( L % a || L%b )
        printf("impossible\n");
        else
        {    int i  , j;
             LL res = 1 ;
             for ( i = 0 ; i < idx && (L>1 || a>1 || b>1) ; i++)
             {
                 int cnt = 0 , cnt1 = 0 , cnt2 = 0 ;
                 while(L%prime[i]==0) cnt++, L/=prime[i];
                 while(a%prime[i]==0) cnt1++ , a/=prime[i];
                 while(b%prime[i]==0) cnt2++, b/=prime[i];
                 if( cnt > max ( cnt1 , cnt2 ))
                 rep(j,cnt) res *= prime[i];


             }
             if(L>1) res*=L;
             printf("%lld\n",res);
        }
    }

   return 0;
}
