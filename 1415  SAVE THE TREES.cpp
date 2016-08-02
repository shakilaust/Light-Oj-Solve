
//BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopner soman boro
 all my suceesses are dedicated to my parents
 Author :: Shakil Ahmed
.............AUST_CSE27.........
 prob   ::
 Type   ::
 verdict::
 Special thanx to Ahmed Faiyaz vai :D
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

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

/* **************************************  My code start here ****************************************** */
const int NX = 2e5 + 10  ;
const Long INF = 1e17 + 10 ;
Long tree[(4*NX)] , Lazy[(4*NX)] ;
int prv[NX] , last[NX] , typed[NX] ; Long H[NX] ;

struct abc
{
    int lft , rgt ; Long height ;
    abc() {}
    abc( int a , int b , Long c)
    {
        lft = a ;
        rgt = b ;
        height = c ;
    }
};
stack < abc > st ;
void LazyPropagate( int node , int lft , int rgt)
{
    tree[node] += Lazy[node];
    if( lft < rgt )
    {
        Lazy[2*node] += Lazy[node];
        Lazy[(2*node) + 1 ] += Lazy[node];
    }
    Lazy[node] = 0 ;
}

Long update( int node , int lft , int rgt , int a , int b , Long val )
{
    if( Lazy[node] ) LazyPropagate(node,lft,rgt);
    if( b < lft || a > rgt ) return tree[node];
    if( a <= lft && b >= rgt )
    {
        tree[node] += val ;
        if( lft != rgt )
        {
            Lazy[2*node] += val ;
            Lazy[(2*node)+1] += val ;
        }
        return tree[node];
    }
    int mid = ( lft +rgt )/2 ;
    tree[node] = min( update(2*node,lft,mid,a,b,val) , update((2*node) + 1 , mid + 1 , rgt , a , b , val));
    return tree[node];
}


Long query( int node , int lft , int rgt , int a , int b)
{
    if( Lazy[node] ) LazyPropagate(node,lft,rgt);
    if( b < lft || a > rgt ) return INF;
    if( a <= lft && b >= rgt )
    {
        return tree[node];
    }
    int mid = ( lft +rgt )/2 ;
    Long ans = min( query(2*node,lft,mid,a,b) , query((2*node) + 1 , mid + 1 , rgt , a , b ));
    return ans;
}


int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
    int t = II , cs ;
    for ( cs = 1 ; cs <= t ; cs++ )
    {
          ms( tree ,  0 );
          ms( Lazy ,  0 );
          ms( last ,  0 );
          int n = II ;
          For( i , n )
          {
              typed[i] = II , H[i] = LL ;
              prv[i] = last[typed[i]];
              last[typed[i]] = i ;
          }
          while( !st.empty() ) st.pop();
          st.push(abc(-1,-1,INF));
          int L = 0 , R = -1 ;
          Long ans ;
          For( i , n )
          {
              L = max( L , prv[i] );
              R++;
              while( st.top().height < H[i] )
              {
                  update(1 , 0 , n , st.top().lft , st.top().rgt , -st.top().height );
                  st.pop();
              }
              st.push(abc(st.top().rgt + 1 , R , H[i] ) );
              update( 1 , 0 , n , st.top().lft, st.top().rgt , st.top().height );
              ans = query( 1 , 0 , n , L , R );
              update( 1 , 0 , n , R + 1 , R + 1 , ans );
          }
          printf("Case %d: %lld\n",cs,ans);
    }

    return 0;
}
