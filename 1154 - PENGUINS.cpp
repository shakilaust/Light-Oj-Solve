
 //BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopner soman boro
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
#define memo(a,b) memset((a),(b),sizeof(a))
#define G() getchar()
#define MAX3(a,b,c) max(a,max(b,c))

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
const int MX = 205 ;
const int INF = (1 << 20);
int deg[MX] , adj[MX][MX] , prev[MX] , cap[MX][MX] , store[MX][MX], q[MX*MX] , n , m , x[MX] , y[MX] , ni[MX] , mi[MX] , Ans[MX];
int dinic(int scr , int sink )
{
    int flow = 0 ;
    while( 1 )
    {


        int qpush = 0 , qpop = 0 , x , u , v;
        memo(prev,-1);
        prev[q[qpush++] = scr ] = -2 ;
        while( qpush > qpop && prev[sink] == -1 )
        {
            int  x = q[qpop++];
            for (   int z = 0 ; z < deg[x] ; z++ )
            {
                int y = adj[x][z] ;
                if( prev[y] == -1 && cap[x][y] > 0 )
                {
                    prev[y] = x ;
                    q[qpush++] = y ;
                }
            }
        }
        if( prev[sink] == -1 ) break ;
        for ( int z = 0 ; z < deg[sink] ; z++ )
        {
            if ( prev[ u = adj[sink][z] ] != -1  && cap[u][sink] > 0 )
            {

                int add = cap[u][sink];

                for ( v = prev[u] ,x = u ; v >= 0  ;  v = prev[v] )
                {

                    add = min(add , cap[v][x] );
                    x = v ;
                }
                if( add == 0 ) continue ;
                cap[u][sink] -= add;
                cap[sink][u] += add;
                 for ( v = prev[u] ,x = u ; v >= 0  ;  v = prev[v] )
                {

                    cap[v][x] -= add;
                    cap[x][v] += add;
                     x = v ;
                }
                flow += add;

            }
        }
    }
    return flow;
}
void input()
{

}
double DIS(int x , int y , int _x , int _y)
{
    return (double) ( x - _x ) * ( x - _x ) + ( y - _y)*(y - _y);
}
void copy_kaj()
{
    int i , j ;
    for ( i = 0 ; i <= n+n+1 ; i++ )
    {
        for( j = 0 ; j <= n+n+1 ; j++ ) cap[i][j] = store[i][j];
    }
}
void solve(int cs)
{


   int scr = 0 , sink ;
   int total = 0 , i , j;
   double dist ;
   cin >>  n >> dist ;
   dist = dist*dist;
   memo(cap,0);
   memo(deg,0);
   for( i = 1 ; i <= n ; i++ )
   {
       cin >> x[i] >> y[i] >> ni[i] >> mi[i];
       total += ni[i];
       adj[scr][deg[scr]++] = i ;
       adj[i][deg[i]++] = scr ;
       cap[scr][i] = ni[i];
       cap[i][i+n] = mi[i] ; // dummy node add korchi
       adj[i][deg[i]++] = i+n;
       adj[i+n][deg[i+n]++] = i ;

       for( j = 1 ; j < i ; j++ )
       {
           if( DIS(x[i],y[i],x[j],y[j]) <= dist ) // possible ek move e asa
           {
               adj[i+n][deg[i+n]++] = j ;
               adj[j][deg[j]++] = i+n ;
               adj[j+n][deg[j+n]++] = i ;
               adj[i][deg[i]++] = j+n ;
               cap[i+n][j] = INF ; // any of penguin
               cap[j+n][i] = INF ;
           }
       }
   }
 //  cout << " total " << total << endl ;
  //  copy option we need to copy every time
  /* for( i = 0 ; i <= n+n+n ; i++ )
   {
       for( j = 0 ; j <=n+n+1 ; j++ )
       store[i][j] = cap[i][j];
   } */
   memcpy(store,cap,sizeof(cap));
   int idx = 0 ;
   for ( i = 1 ; i <= n ; i++ )
   {
       sink = i ;
       if( total == dinic(scr,sink) )
       {
           Ans[idx++] = i-1;


       }
         memcpy(cap,store,sizeof(store));
       // copy_kaj();
   }
   printf("Case %d:",cs);
   if(idx)
   {
       for( i = 0 ; i < idx ; i++ )
       {

           printf(" %d",Ans[i]);

       }
       printf("\n");
   }
   else puts(" -1");




}
int main()
{

    int cs , t ;
    read(t);
    for ( cs = 1 ; cs <=t ; cs++ )
    {

        solve(cs);
    }

    return 0;
}
/*
2
5 3.5
1 1 1 1
2 3 0 1
3 5 1 1
5 1 1 1
5 4 0 1
3 1.1
-1 0 5 10
0 0 3 9
2 0 1 1

*/
