

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

// Mid in the middle technique
const int Maxn = 1000005;
int a[Maxn] , b[Maxn] , n , k , inp[30] , Idxa , Idxb;
bool Possible(int val)
{
    if(!val) return 1 ; // Its possible by only using a array no need to b array's value
    int left = 0 , right = Idxb ;
    while ( left <= right )
    {
        int mid = ( left + right ) / 2 ;
       // printf("val :: %d b[mid]::%d\n",val,b[mid]);
        if ( b[mid] == val ) return 1;
        if ( b[mid] > val ) right = mid - 1;
        else left = mid + 1 ;
    }
    return false;

}
void AlL_possibleA(int left , int right , int val)
{   //printf("Left :: %d right :: %d\n",left , right);
    if (left >  right )
    {
        a[Idxa++] = val ;
       // printf("val::%d here\n",val);
        return ;
    }
    int i ;
    for ( i = 0 ; i < 3 ; i++ )
    {
        AlL_possibleA(left+1,right,val+(inp[left]*i));
    }
}
void AlL_possibleB(int left , int right , int val)
{  // printf("Left :: %d right :: %d\n",left , right);
    if (left > right )
    {
        b[Idxb++] = val ;
        return ;
    }
    int i ;
    for ( i = 0 ; i < 3 ; i++ )
    {
        AlL_possibleB(left+1,right,val+(inp[left]*i));
    }
}
int main()
{
    int cs , t ;
    read(t) ;
    for ( cs = 1 ; cs <= t  ; cs++ )
    {
        read(n) , read(k) ;
       // printf("n::%d k::%d\n",n,k);
        int i ;

        rep(i,n) read(inp[i]);
        Idxa = 0 , Idxb = 0 ;
        AlL_possibleA(0,n/2,0);
        AlL_possibleB(n/2+1,n-1,0);
        sort(b,b+Idxb);
        bool prnt = 0 ;
        printf("Case %d: ",cs);
        for ( i = 0  ; i < Idxa ; i++ )
        {   // printf("k::%d a[i]::%d k-a[i]::%d\n",k,a[i],k-a[i]);
            if ( k>=a[i] && Possible(k-a[i]))
            {
                printf("Yes\n");
                prnt = 1 ;
                break;
            }
        }
        if(prnt) continue;
        printf("No\n") ; // not possible

    }
   return 0;
}
