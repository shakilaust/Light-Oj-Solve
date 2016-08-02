
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
typedef long long ll;
const ll mod = (ll)1000000007;
const int maxn = (int) 1e5 + 10 ;
vector <int> prime;
bool check[maxn];
ll n , m ;
vector < pair < ll , ll > > primfact;

void PrimeFactor(ll x)
{
    int i , sz = prime.size() ;
    for ( i = 0 ; prime[i]*prime[i] <= x && i < sz ; i++ )
    {
        if(x % prime[i]==0)
        {
            ll cnt = 0 ;
            while( x % prime[i] == 0 )
            {
                x /= prime[i];
                cnt++;
                //cout<<x<<" "<<prime[i]<<endl;
            }
            //cout<<cnt<<" "<<(cnt*m)<<endl;
            primfact.pb(mp(prime[i],cnt*m));
        }
    }
    if( x > 1 )
    {
        primfact.pb(mp(x,m));
    }
}
void seive()
{
    int i , j ;
    prime.pb(2);
    for ( i = 3 ; i*i < maxn ; i+= 2)
    {
        if(check[i]==0)
        {
            prime.pb(i);
            for ( j = (i*i) ; j < maxn ; j+= (2*i))
            {
                check[j] = 1 ;
            }
        }
    }
    while( i < maxn )
    {
        if(check[j]==0) prime.pb(i);
        i += 2 ;
    }
}
int main()
{
  // freopen("input.txt","r",stdin);
     //freopen("output.txt","w",stdout);
    // ll a , b , n ;
    seive();
    int cs , t ;
    read(t) ;
    for ( cs = 1 ; cs <= t ; cs++ )
    {
        read(n) , read(m) ;
        primfact.clear();
        PrimeFactor(n);
        ll ans = 1 ;
        int i , sz = primfact.size();
        for ( i = 0 ; i < sz ; i++ )
        {
           // cout<<primfact[i].first<<" "<<primfact[i].second<<endl;
            ll x = ((bigmod(primfact[i].first,primfact[i].second+1,mod) - 1)+mod)%mod ;
            ll y = modinverse(primfact[i].first-1,mod);
           // printf("x :: %lld y::%lld\n",x,y);
            ans = ( ans%mod * x%mod *y%mod)%mod;
        }
        printf("Case %d: %lld\n",cs,ans);
    }
   return 0;
}
