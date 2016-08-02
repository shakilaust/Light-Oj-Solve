
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
#define INF 1<<28
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define memo(a,b) memset((a),(b),sizeof(a))
#define G() getchar()
#define MAX3(a,b,c) max(a,max(b,c))

double const EPS=3e-8;
using namespace std;
const int MAX_N = 50005;

int N, m, SA [MAX_N], LCP [MAX_N];
int x [MAX_N], y [MAX_N], w [MAX_N], c [MAX_N];
int lena , lenb , lenc  ;
string str , a , b , cc ;
inline bool cmp (const int a, const int b, const int l) { return (y [a] == y [b] && y [a + l] == y [b + l]); }

void Sort () {
    for (int i = 0; i < m; ++i) w [i] = 0;
    for (int i = 0; i < N; ++i) ++w [x [y [i]]];
    for (int i = 0; i < m - 1; ++i) w [i + 1] += w [i];
    for (int i = N - 1; i >= 0; --i) SA [--w [x [y [i]]]] = y [i];
}

void DA () {
    ++N;
    for (int i = 0; i < N; ++i) x [i] = str [i], y[i] = i;
    Sort ();
    for (int i, j = 1, p = 1; p < N; j <<= 1, m = p) {
        for (p = 0, i = N - j; i < N; i++) y [p++] = i;
        for (int k = 0; k < N; ++k) if (SA [k] >= j) y [p++] = SA [k] - j;
        Sort ();
        for (swap (x, y), p = 1, x [SA [0]] = 0, i = 1; i < N; ++i) x [SA [i]] = cmp (SA [i - 1], SA [i], j) ? p - 1 : p++;
    }
    for (int i = 1; i < N; ++i) SA [i - 1] = SA [i]; --N;
}

void kasaiLCP () {
    for (int i = 0; i < N; ++i) c [SA [i]] = i;
    LCP [0] = 0;
    for (int i = 0, h = 0; i < N; ++i) if (c[i] > 0) {
            int j = SA [c [i] - 1];
            while (i + h < N && j + h < N && str [i + h] == str [j + h]) ++h;
            LCP [c [i]] = h;
            if (h > 0) --h;
        }
}

void suffixArray () {
    m = 256;

    N = str.size() ;
    DA ();
    kasaiLCP ();
}
void add( int &x , int &y , int &z , int val )
{
    if(  val < lena ) x += 1 ;
    else if( val > lena && val < ( lenb) ) y += 1 ;
    else if ( val > ( lenb) ) z += 1 ;
}
bool check( int lim)
{
    int i , x  , y , z , j ;
    for ( i = 1 ; i < N ; i++ )
    {
        if( LCP[i] < lim ) continue ;
        x = y = z = 0 ;
        add( x , y , z , SA[i] );
        if( x == 0 && y == 0 && z == 0 ) continue ;
        add( x , y , z , SA[i-1] );
        j = i + 1 ;
        while( j < N && LCP[j] >= lim && !( x > 0 && y > 0 && z > 0 ) )
        {
            add( x , y , z , SA[j] );
            j++;
        }
        if( x > 0 && y > 0 && z > 0 ) return 1 ;

    }
    return 0 ;
}
int solve()
{
    int low = 0 , high = min( lena , min( lenb , lenc ) ) , ans , mid ;
    while( low <= high )
    {
        mid = ( low + high )/2 ;
        if( check(mid) )
        {
            ans = mid ;
            low = mid + 1 ;
        }
        else high = mid - 1 ;
    }
    return ans ;

}
int main()
{

       int cs , t ;
       scanf("%d",&t);
       for ( cs = 1 ; cs <= t ; cs++ )
       {

             cin >> a >> b >> cc ;
             str = a + '#' + b + '&' + cc ;
             lena = a.size();
             lenb = lena + 1 + b.size();
             lenc = str.size() ;
             suffixArray();

             printf("Case %d: %d\n",cs,solve());

       }




    return 0;
}
