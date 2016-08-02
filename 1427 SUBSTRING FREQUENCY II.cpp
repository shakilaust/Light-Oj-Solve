
//BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopner soman boro
 all my suceesses are dedicated to my parents
 Author :: Shakil Ahmed
.............AUST_CSE27.........
 prob   ::
 Type   ::
 verdict::
   Special Thanks goes to Rajon :)
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

template< class T > T gcd(T a, T b)
{
    return (b != 0 ? gcd<T>(b, a%b) : a);
}
template< class T > T lcm(T a, T b)
{
    return (a / gcd<T>(a, b) * b);
}

//Fast Reader
template<class T>inline bool read(T &x)
{
    int c=getchar();
    int sgn=1;
    while(~c&&c<'0'||c>'9')
    {
        if(c=='-')sgn=-1;
        c=getchar();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=getchar())x=x*10+c-'0';
    x*=sgn;
    return ~c;
}

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

/* **************************************  My code start here ****************************************** */

const int NX = 502 ;
const int MX = 1e6 + 10 ;
const int MXS = ( NX * NX ) + 2 ;


char inp[NX][NX] , txt[MX] ;
int Len[NX] , n , Ans[NX] ;
int trie[MXS][30];
int failure[MXS];
int Q[ MXS ] ;
bitset < NX > Out[ MXS ] ;

void BuildMachine()
{
    ms( failure , -1 );
    ms( trie ,  -1 );
    ms( Out , 0 );
    int states = 0 ;
    For( i , n )
    {
        int currentstate = 0 ;
      //  printf( " len :: %d\n" , Len[i] );
        rep( j , Len[i] )
        {
            int c = inp[i][j] - 'a' ;
            if(trie[currentstate][c]==-1)
            {
                trie[currentstate][c] = ++states ;
            }
            currentstate = trie[currentstate][c] ;

        }
        Out[currentstate].set(i);
     //   printf("Currentstate :: %d i :: %d\n",currentstate , i );
    }
    rep( i , 26 ) if( trie[0][i] == -1 ) trie[0][i] = 0 ;
    int t = 0 , b = 0 ;
    rep( i , 26 )
    {
        if( trie[0][i] != -1 && trie[0][i] != 0 )
        {
            failure[trie[0][i]] = 0 ;
            Q[t++] = trie[0][i];
        }
    }
    while( b < t )
    {
        int state = Q[b++];
        rep( i , 26 )
        {
            if( trie[state][i] != -1 )
            {
                int fail = failure[state];
                while( trie[fail][i] == -1 ) fail = failure[fail];
                fail = trie[fail][i];
                failure[trie[state][i]] = fail ;
                Out[trie[state][i]] |= Out[fail];
                Q[t++] = trie[state][i];
            }
        }
    }

}

int findNextState( int state , int c )
{
    while( trie[state][c] == -1 ) state = failure[state] ;
    return trie[state][c];
}
int main()
{
    int cs , t = II ;
    for ( cs = 1 ; cs <= t ; cs++ )
    {
        n = II ;
        scanf("%s",txt);
        For( i , n )
        {
            scanf("%s",inp[i]);
            Len[i] = strlen(inp[i]);
            Ans[i] = 0 ;
        }
        BuildMachine();
        //scanf("%s",txt);
        int sz = strlen(txt);
        int currentstate = 0 ;
        rep( i , sz )
        {
            int now = txt[i] -'a';
            currentstate = findNextState( currentstate , now );
            if( Out[currentstate] == 0 ) continue ;
            For( j , n )
            {
                if( Out[currentstate].test(j) ) Ans[j]++;
            }
        }
        printf("Case %d:\n",cs);
        For( i , n )  printf("%d\n",Ans[i]);
    }
    return 0 ;
}
