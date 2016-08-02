
 //BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopner soman boro
 Author :: Shakil Ahmed
.............AUST_CSE27.........
 prob   ::  Loj_1127
 Type   :: meet_in_the_middle
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
#define MAX (2*8000+5)
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
//Fast Reader
template<class T>inline bool read(T &x){int c=getchar();int sgn=1;while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}for(x=0;~c&&'0'<=c&&c<='9';c=getchar())x=x*10+c-'0'; x*=sgn; return ~c;}
typedef long long ll ;

vector < ll > v1 , v2 ;
int n ;
ll w , Inp[50] ;
void Setv1(int pos , ll sum)
{
    if ( pos == (n/2) )
    {
        v1.pb(sum) ;
        return ;
    }
    Setv1(pos+1,sum);
    if( sum + Inp[pos] <= w ) Setv1(pos+1,sum+Inp[pos]);
}
void Setv2(int pos , ll sum)
{
    if ( pos == n )
    {
        v2.pb(sum) ;
        return ;
    }
    Setv2(pos+1,sum);
    if( sum + Inp[pos] <= w ) Setv2(pos+1,sum+Inp[pos]);
}
int main()
{

    //freopen("in.txt", "r", stdin);
    int cs , t ;
    read(t);

    for ( cs = 1 ; cs <= t ; cs++ )
    {
        read(n) , read(w) ;
        int i ;
        for ( i = 0 ; i < n ; i++ )
        {
            read(Inp[i]);
        }
        v1.clear();
        v2.clear();
        Setv1(0,0);
        Setv2(n/2,0);
        sort(v1.begin(),v1.end());
        int sz = v2.size() ;
        ll Ans = 0 ;
        for ( i = 0 ; i < sz ; i++ ) Ans += upper_bound(v1.begin(),v1.end(),w-v2[i]) - v1.begin();
        printf("Case %d: %lld\n",cs,Ans);
    }





}
