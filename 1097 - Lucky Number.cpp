

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
//template<class T>inline bool read(T &x){int c=getchar();int sgn=1;while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}for(x=0;~c&&'0'<=c&&c<='9';c=getchar())x=x*10+c-'0'; x*=sgn; return ~c;}

/* **************************************  My code start here ****************************************** */
const int MaxVal  = 15000000;
int tree[MaxVal+5] = {0} , ans[100005];
int read(int idx)
{
    int sum = 0 ;
    while(idx>0)
    {
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum ;
}
void update(int idx , int val)
{

    while(idx<=1429431)
    {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}
// Return the index where we found the cf value
int binarysearch(int val)
{
    int left = 1 , right = 1429431 , mid ;
    while(left <= right )
    {
        mid = ( left + right ) / 2 ;
        bool found = false ;
        while( mid >0 && read(mid)==val)
        {   --mid;
            found = true ;
        }
        if(found) return mid + 1 ;
        int tmp = read(mid);
       // printf("mid :: %d tmp :: %d \n",mid, tmp);
        if ( tmp > val ) right = mid - 1;
        else left = mid + 1 ;
    }
    return -1;
}
void ini()
{   // printf("here \n");
    int i , j , k;
    for ( i = 1 ; i <=MaxVal ; i+=2 ) update(i,1);
    ans[1] = 1;

    for ( i = 2 ; i<= 100000 ; i++ )
    {
        int tmp = binarysearch(i);

        if( tmp == -1 ) break;
        ans[i] = tmp ;
        for ( j = tmp ; j <= 1429431 ; j+= (tmp-1))
        {
            k = binarysearch(j) ;
            if ( k == -1 ) // no need to continue ;
            break ;
            update(k,-1);
        }
    }

}
int main()
{
    int cs , t , inp ;
    ini();
    scanf("%d",&t);

    for ( cs = 1 ; cs <= t ; cs++ )
    {
        scanf("%d",&inp);
        printf("Case %d: %d\n",cs,ans[inp]);
    }
   return 0;
}
