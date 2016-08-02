
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
#define MAX  1000003
#define MOD  1000003
#define INF 1<<30
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define memo(a,b) memset((a),(b),sizeof(a))
#define G() getchar()


using namespace std;


template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
long long fact[MAX];
void pre()
{
       int i;
       fact[0]=fact[1]=1;
       for(i=1;i<MAX;i++)
         fact[i]=(fact[i-1]*i)%MOD;

}
long long BigMod(long long a,long long b,long long m)
{
       if(b==0) return 1;
       long long x=BigMod(a,b/2,m);
       x=(x*x)%m;
       if(b%2)
       x=(x*a)%m;
       return x;
}
long long ModInverse(long long a,long long m)
{
       return BigMod(a,m-2,m);
}


int main()
{

    //freopen("in.txt", "r", stdin);
    int cs,T;
    pre();
    sc(T);
    FOR(cs,1,T)
    {
           int n,r;
           scanf("%d %d",&n,&r);
           printf("Case %d: %lld\n",cs,((fact[n]*ModInverse(fact[r],MOD))%MOD * ModInverse(fact[n-r],MOD))%MOD);
    }



}
