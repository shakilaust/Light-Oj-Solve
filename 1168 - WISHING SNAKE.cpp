
//BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopner soman boro
 all my suceesses are dedicated to my parents
 Author :: Shakil Ahmed
.............AUST_CSE27.........
 prob   ::
 Type   ::
 verdict::
 */

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pi acos(-1.0)
#define ff first
#define ss second
#define re return
#define QI queue<int>
#define SI stack<int>
#define SZ(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define ms(a,b) memset((a),(b),sizeof(a))
#define G() getchar()
#define MAX3(a,b,c) max(a,max(b,c))
#define II ( { int a ; read(a) ; a; } )
#define LL ( { Long a ; read(a) ; a; } )
#define DD ({double a; scanf("%lf", &a); a;})

double const EPS=3e-8;
using namespace std;

#define FI freopen ("input.txt", "r", stdin)
#define FO freopen ("output.txt", "w", stdout)

typedef long long Long;
typedef long long int64;
typedef unsigned long long ull;
typedef vector<int> vi ;
typedef set<int> si;
typedef vector<Long>vl;
typedef pair<int,int>pii;
typedef pair<string,int>psi;
typedef pair<Long,Long>pll;
typedef pair<double,double>pdd;
typedef vector<pii> vpii;

// For loop

#define forab(i, a, b)	for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n)		forab (i, 0, (n) - 1)
#define For(i, n)		forab (i, 1, n)
#define rofba(i, a, b)	for (__typeof (b)i = (b) ; i >= a ; --i)
#define per(i, n)		rofba (i, 0, (n) - 1)
#define rof(i, n)		rofba (i, 1, n)
#define forstl(i, s)	for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)

template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }

//Fast Reader
template<class T>inline bool read(T &x){int c=getchar();int sgn=1;while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}for(x=0;~c&&'0'<=c&&c<='9';c=getchar())x=x*10+c-'0'; x*=sgn; return ~c;}

int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

/* **************************************  My code start here ****************************************** */
const int NX = 1005 ;
int discover[NX] , low[NX] , In[NX] , Out[NX] , deg[NX] , adj[NX][NX] , Instack[NX];
int Color[NX] , id , now ;
stack < int > s ;
set < int > present ;
void dfs( int u )
{
    discover[u] = low[u] = ++now ;
    Instack[u] = 1 ;
    s.push(u);
    rep( i , deg[u] )
    {
        int x = adj[u][i];
        if( discover[x] == -1 )
        {
            dfs(x);
            low[u] = min( low[u] , low[x] );
        }
        else if( Instack[x] )
            low[u] = min(discover[x],low[u]);
    }
    if( discover[u] == low[u] )
    {
        ++id ;
        int tt ;
        do
        {
            tt = s.top();
            Instack[tt] = 0 ;
            Color[tt] = id ;
            s.pop();
        }while( u != tt );
    }
}

bool solve()
{
    now = 0 ;
    id = 0 ;
    ms( discover , -1 );
    while( !s.empty() ) s.pop();
    forstl(it , present )
    {
        if( discover[*it] == -1 ) dfs(*it);
    }
    ms( In , 0 );
    ms( Out , 0 );
    forstl(it , present )
    {
        rep( i , deg[*it] )
        {
            int to = adj[*it][i];
            if( Color[to] != Color[*it] )
            {
                Out[Color[*it]]++;
                In[Color[to]]++;
            }
        }
    }
    if( id <= 1 )return 1 ;
    if( discover[0] == -1 || Out[Color[0]] != 1 || In[Color[0]] != 0 ) return 0 ;

    int sink = 0 ;
    For( i , id )
    {
        if( i == Color[0] ) continue ;
        if( In[i] == 1 && Out[i] == 0 )
        {
            sink++;
            if( sink > 1 ) return 0 ;
        }
        else
        {
            if( In[i] == 1 && Out[i] == 1 ) continue ;
            else return 0 ;
        }
    }
    return 1 ;

}
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
    int cs , t = II ;
    for( cs = 1 ; cs <= t ; cs++ )
    {
        ms( deg , 0 );
        present.clear();
        int n = II ;
        bool ok = 0 ;
        rep( i , n )
        {
            int x = II ;
            while( x-- )
            {
                int a = II , b = II ;
                adj[a][deg[a]++] = b ;
                ok |= !a ;
                present.insert(a);
                present.insert(b);
            }
        }
        printf("Case %d: %s\n",cs, ok && solve()? "YES" : "NO");

    }

    return 0;
}
