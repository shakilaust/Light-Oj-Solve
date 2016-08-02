
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
#define QI queue<Long>
#define SI stack<Long>
#define SZ(x) ((Long) (x).size())
#define all(x) (x).begin(), (x).end()
#define sq(a) ((a)*(a))
#define distance(a,b) (sq(a.x-b.x) + sq(a.y-b.y))
#define iseq(a,b) (fabs(a-b)<eps)
#define eq(a,b) iseq(a,b)
#define ms(a,b) memset((a),(b),sizeof(a))
#define G() getchar()
#define MAX3(a,b,c) max(a,max(b,c))
#define II ( { Long a ; read(a) ; a; } )
#define LL ( { Long a ; read(a) ; a; } )
#define DD ({double a; scanf("%lf", &a); a;})

double const EPS=3e-8;
using namespace std;

#define FI freopen ("input.txt", "r", stdin)
#define FO freopen ("output.txt", "w", stdout)

typedef long long Long;
typedef long long int64;
typedef unsigned long long ull;
typedef vector<Long> vi ;
typedef set<Long> si;
typedef vector<Long>vl;
typedef pair<Long,Long>pii;
typedef pair<string,Long>psi;
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

//template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
//template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }

//Fast Reader
template<class T>inline bool read(T &x){Long c=getchar();Long sgn=1;while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}for(x=0;~c&&'0'<=c&&c<='9';c=getchar())x=x*10+c-'0'; x*=sgn; return ~c;}

//Long dx[]={1,0,-1,0};Long dy[]={0,1,0,-1}; //4 Direction
//Long dx[]={1,1,0,-1,-1,-1,0,1};Long dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//Long dx[]={2,1,-1,-2,-2,-1,1,2};Long dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//Long dx[]={2,1,-1,-2,-1,1};Long dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

/* **************************************  My code start here ****************************************** */

// code for Linear Diophantine equations
/*
You have to find the number of solutions of the following equation:

Ax + By + C = 0

Where A, B, C, x, y are integers and x1 ≤ x ≤ x2 and y1 ≤ y ≤ y2. */

int64 x, y, d;


void extEuclid(int64 a, int64 b) {
	if (b == 0) { x = 1; y = 0; d = a; return; }
	extEuclid(b, a % b);
	x = x - (a / b) * y;
	swap(x, y);
}

int64 solve(int a, int b, int c, int64 x1, int64 x2, int64 y1, int64 y2) {
	extEuclid(a, b);
	if (!a && !b) {
		if (c) return 0;
		return (x2 - x1 + 1) * (int64)(y2 - y1 + 1);
	}
	else if (!a) {
		if (c % b) return 0;
		c = -c / b;
		if (y1 <= c && c <= y2) return (x2 - x1 + 1);
		return 0;
	}
	else if (!b) {
		if (c % a) return 0;
		c = -c / a;
		if (x1 <= c && c <= x2) return (y2 - y1 + 1);
		return 0;
	}
	if (c % d == 0) {
		//d = abs(d);
		x *= (-c / d); y *= (-c / d);
		b /= d; a /= d;
		swap(a, b); // x + ka, y - kb
		double p = (x1 - x) / (double)a, q = (x2 - x) / (double)a;
		if (p > q) swap(p, q);
		x1 = (int64)ceil(p);
		x2 = (int64)floor(q);

		p = (y - y1) / (double)b; q = (y - y2) / (double)b;
		if (p > q) swap(p, q);
		y1 = (int64)ceil(p);
		y2 = (int64)floor(q);

		//printf("xy %lld %lld : ab %d %d : x %lld %lld : y %lld %lld\n", x, y, a, b, x1, x2, y1, y2);

		x1 = max(x1, y1); x2 = min(x2, y2);
		return max(0LL, x2 - x1 + 1);
	}
	return 0;
}
int main()
{
   // I will always use scanf and prLongf
   // May be i won't be a good programmer but i will be a good human being
    int cs , t = II ;
    for ( cs = 1 ; cs <= t ; cs++ )
    {
        Long A  = LL , B = LL , C = LL , x1 = LL , x2 = LL , y1 = LL , y2 = LL ;
        printf("Case %d: %lld\n",cs,solve( A , B , C , x1 , x2 , y1 , y2 ) );
    }

    return 0;
}
