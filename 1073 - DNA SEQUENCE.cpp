
 //BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopner soman boro
 Author :: Shakil Ahmed
.............AUST_CSE27.........
 prob   ::  Loj 1073
 Type   ::  Dp
 verdict::
 Special Thanx to Hasib Billah :D
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
const int MaxN = 105 ;
const int N = 16 ;
int pi[N][(1<<N)] , dp[N][(1<<N)] , vis[N][1<<N] , length[N], cs  , n ;
string str[N] ;
vector <int> adjList[N];

void input()
{
    int i;
    scanf("%d",&n);
    rep(i,n)
    {
        cin >> str[i];
        adjList[i].clear();
    }

}

void failure(int idx)
{
    int i , j = 0 ;
    pi[idx][1] = 0 ;
    for ( i = 2 , j = 0 ; i <= length[idx] ; i++ )
    {
        while( j > 0 && str[idx][i-1] != str[idx][j] ) j = pi[idx][j];
        pi[idx][i] = (j += (str[idx][i-1] == str[idx][j]) );
    }
}
int kmp(int fst , int secnd ) // we found out second string is on first string or no
{
    int i , j ;
    for  ( i = 0 , j = 0; i < length[fst] ; i++ )
    {
        while( j > 0 && str[secnd][j] != str[fst][i] ) j = pi[secnd][j] ;
        j += (str[secnd][j] == str[fst][i]);
        if ( j == length[secnd] ) return 0 ;
        if ( i == length[fst] - 1 ) return length[secnd] - j ;
    }
}
int DP(int last , int mask )
{
    if ( mask + 1 == ( 1 << n ) ) return 0 ;
    int &ret = dp[last][mask];
    if ( vis[last][mask] == cs ) return ret ;
    vis[last][mask] = cs ;
    int i ;
    ret = INF ;
    for ( i = 0 ; i < n ; i++ )
    {
        if(mask & ( 1 << i )) continue ;
        ret = min(ret , DP(adjList[last][i]?i:last,mask | (1 << i))+adjList[last][i]);
    }
    return ret;
}
void print(int last , int mask )
{
    if ( ( 1 << n ) == ( mask) + 1 )
    {
        cout << endl ;
        return ;
    }
    string minstr = "Z" ;
    int i  , minpos;
    for ( i = 0 ; i < n ; i++ )
    {
        if ( mask & ( 1 << i )) continue ;
        int tmp = adjList[last][i]?i:last ;
        if( DP(last,mask) == DP(tmp , mask | (1 << i)) + adjList[last][i] )
        {
            string tmpstr = ( tmp == last) ? "" : str[i].substr(length[i] - adjList[last][i]);
            if(minstr > tmpstr )
            {
                minstr = tmpstr ;
                minpos = i ;
            }
        }
    }
    cout << minstr ;
    print(minstr==""?last:minpos,mask | ( 1 << minpos) );
}
void solve()
{
    int i , j , minpos , res = INF;
    sort(str,str+n);
    rep(i,n) { length[i] = str[i].size(); failure(i) ; }
    for ( i = 0 ; i < n ; i++ )
    {
        for ( j = 0 ; j < n ; j++)
        {
            adjList[i].pb(kmp(i,j));
        }
    }
   // rep(i,n)
    // rep(j,adjList[i].size()) printf("i :: %d j::%d ken :: %d\n",i,j,adjList[i][j]);
    for ( i = 0 ; i < n ; i++ )
    {
        int tmp = DP(i,(1 << i)) + length[i] ;
        if(res > tmp )
        {
            res = tmp ;
            minpos = i ;
        }
    }
    cout << str[minpos];
    print(minpos,1<<minpos);
}
int main()
{
    int t ;
    read(t);
    for ( cs = 1 ; cs <= t ; cs++ )
    {
        input();
        printf("Case %d: ",cs);
        solve();
    }
   return 0;
}
