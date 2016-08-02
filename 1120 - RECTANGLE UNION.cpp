
//BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopner soman boro
 all my suceesses are dedicated to my parents
 The true test of a man's character is what he does when no one is watching.


 Author :: Shakil Ahmed
.............AUST_CSE27.........
 prob   ::
 Type   ::
 verdict::
 */

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair

// Macro
#define eps 1e-9
#define pi acos(-1.0)
#define ff first
#define ss second
#define re return
#define QI queue<int>
#define SI stack<int>
#define SZ(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sq(a) ((a)*(a))
#define distance(a,b) (sq(a.x-b.x) + sq(a.y-b.y))
#define iseq(a,b) (fabs(a-b)<eps)
#define eq(a,b) iseq(a,b)
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

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

/* **************************************  My code start here ****************************************** */

const int NX = 30000 + 10 ;

struct Line
{
    int x , ymin , ymax , op ;
    Line() { }
    Line( int _x , int _ym , int _ymx , int _op )
    {
        x = _x ;
        ymin = _ym ;
        ymax = _ymx ;
        op = _op ;
    }
    bool operator < ( const Line &e ) const
    {
        return x < e.x ;
    }
};
Line inp[ ( NX << 5) + 1] ;

Long sum[ ( NX << 5 ) + 1 ] , h[ ( NX << 5 ) + 1 ] , lazy[ ( NX << 5 ) + 1 ];

int n , m , l ;

void compress()
{
    int k = 1 ;
    for ( int i = 2 ; i <= m ; i++ ) if( h[k] != h[i] )
    {
        h[++k] = h[i];
    }
    m = k ;
}

void update( int node , int l , int r , int x , int y , int op )
{
    int lchild = node * 2 ;
    int rchild = lchild + 1 ;
    int mid = ( l + r ) / 2 ;
    if( h[r] < x || h[l] > y ) return ; // out of boundary
    if( h[l] >= x && h[r] <= y )
    {
        lazy[node] += op ? 1 : -1  ;
        if( lazy[node] ) sum[ node ] = h[r] - h[l] ;
        else sum[ node ] = sum[ lchild ] + sum[ rchild ] ;
        return ;
    }
    if( l + 1 >= r ) return ; // no need to processed
    update( lchild , l , mid , x , y , op );
    update( rchild , mid  , r , x , y , op );
    if( lazy[node] ) sum[ node ] = h[r] - h[l] ;
    else sum[node] = sum[lchild] + sum[rchild];
}
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good  programmer but i will be a good human being
    int cs , t = II ;
    for ( cs = 1 ; cs <= t ; cs++ )
    {
        n = II ;
        l = 0 , m = 0 ;
        rep ( i , n )
        {
            int x1 = II , y1 = II , x2 = II , y2 = II ;
            inp[ l++ ] = Line( x1 , y1 , y2 , 1 );
            inp[ l++ ] = Line( x2 , y1 , y2 , 0 );
            h[ ++m ] = y1 ;
            h[ ++m ] = y2 ;
        }

        sort( inp , inp + l );
        sort( h + 1 , h + 1 + m );

        compress();
        int i , lim = ( NX << 3 ) ;
        for ( i = 0 ; i <= lim ; i++ )
        {
            lazy[i] = sum[i] = 0 ;
        }
        update( 1 , 1 , m , inp[0].ymin , inp[0].ymax , inp[0].op );

        Long ans = 0 ;
        for ( i = 1 ; i < l ; i++ )
        {
            ans += sum[1] * (Long) (inp[i].x - inp[i-1].x);
            update( 1 , 1 , m , inp[i].ymin , inp[i].ymax , inp[i].op );

        }
        printf("Case %d: %lld\n",cs,ans);


    }
    return 0;
}
