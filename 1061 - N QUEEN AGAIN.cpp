

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
struct Board
{
    int x[8], y[8];
}temp, brd[100] , cur;
int idx = 0;
string inp[10];
int dp[10][8<<1 + 5];
bool can(int n ,int x, int y, Board &tmp)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(y==tmp.y[i] || abs(x-tmp.x[i])==abs(y-tmp.y[i]) ) return false;
    }
    return true;
}
void input()
{
    int i;
    for(i=0;i<8;i++) cin>>inp[i];
}

void pre(int r, Board &tmp)
{   /* bractracing er madhome pre generate kore rakhtechi all possible chess board position */
    if( r == 8 )
    {
        brd[idx++] = tmp;
    }
    int i;
    for(i=0;i<8;i++)
    {
        if(can(r,r,i,tmp))
        {
            tmp.x[r] = r;
            tmp.y[r] = i;
            pre(r+1,tmp);
        }
    }
}
int distance(Board &a , Board &b , int i , int j)
{
    int r1 = a.x[i];
    int c1 = a.y[i];
    int r2 = b.x[j];
    int c2 = b.y[j];
    if(r1==r2 && c1==c2) return 0;
    else if( (r1==r2) || c1==c2 || abs(r1-r2)==abs(c1-c2) ) return 1;
    else return 2;
}
int DP(int r,int mask,int idx)
{
    if(r==8) return 0;
    int &ret=dp[r][mask];
    if(ret != -1) return ret;
    ret = INF;
    int i;
    for(i=0;i<8;i++)
    {
        if(mask & 1<<i) continue;
        ret = min(ret , distance(brd[idx],cur,i,r) + DP(r+1,mask | 1<<i , idx) );
    }
    return ret;
}

void solve()
{
    int i , j , id = 0;
    for ( i = 0 ; i < 8 ; i++ )
    {
        for(j = 0 ; j < 8 ; j++ )
        {
            if(inp[i][j] == 'q' )
            {
                cur.x[id] = i;
                cur.y[id++] = j;
            }
        }
    }
    int ans = 1000000;
    for ( i = 0 ; i < idx; i++ )
    {
        memo(dp,-1);
        ans = min(ans,DP(0,0,i));
    }
    printf("%d\n",ans);
}
int main()
{
       // freopen("input.txt","r",stdin);
       Board tmp;
       idx = 0;
       pre(0,tmp);
       int cs, t;
       scanf("%d",&t);
       for(cs = 1; cs <= t ; cs++)
       {   input();
           printf("Case %d: ",cs);
           solve();
       }
       return 0;

}
