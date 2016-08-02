

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
struct point
{
    LL x , y;
};
bool cmp(point A , point B)
    {
        if ( A.x==B.x) return A.y<B.y;
        return A.x<B.x;
    }
// 2D cross product.
        // Return a positive value, if OAB makes a counter-clockwise turn,
        // negative for clockwise turn, and zero if the points are collinear.

        double Angle(point A, point B , point C)
        {
            double AB=sqrt( (double)((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y)));
            //cout<<A.x<<"__"<<A.y<<"__"<<B.x<<"__"<<B.y<<"__"<<AB<<endl;
            double BC=sqrt( (double)((B.x-C.x)*(B.x-C.x)+(B.y-C.y)*(B.y-C.y)));
            //cout<<B.x<<"__"<<C.x<<"__"<<BC<<endl;
            double CA=sqrt( (double)((C.x-A.x)*(C.x-A.x)+(C.y-A.y)*(C.y-A.y)));
            //cout<<C.x<<"__"<<A.x<<"__"<<CA<<endl;
            double ang=acos((AB*AB+BC*BC-CA*CA)/ ( 2*AB*BC));
            //cout<<"test"<<ang<<endl;
            ang = (ang*((double) 180/pi )); // degree converter

            return ang;
        }
 LL cross(const point &O, const point &A, const point &B)
        {
            return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
        }
vector< point > getConvexHull(vector< point >& P)
        {
            int n = P.size(), k = 0;
            vector< point > H(2*n);
            // Sort points lexicographically
            sort(P.begin(), P.end(),cmp);

            // Build lower hull
            for (int i = 0; i < n; i++) {
                while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--; // strictly counter-clockwise then < 0 (skipping the colinear points)  else use <=0
                H[k++] = P[i];
            }

            // Build upper hull
            for (int i = n-2, t = k+1; i >= 0; i--) {
                while (k >= t && cross(H[k-2], H[k-1], P[i]) <= 0) k--; // strictly counter-clockwise then < 0 (skipping the colinear points)  else use <=0
                H[k++] = P[i];
            }

            H.resize(k);
            //H.pop_back(); // first point comes again . so pop
            return H;
        }
int main()
{
       // freopen("input.txt","r",stdin);
       int cs , t ;
       cin>>t;
       for ( cs = 1  ; cs <= t ; cs++ )
       {
           vector < point> p;
           point inp;
           int n  ,  i , x , y ;
           cin >> n ;
           for( i = 0 ; i < n ; i++ )
           {
               cin >> inp.x >> inp.y ;
               p.pb(inp);

           }
           if(n<3){
                printf("Case %d: 0\n",cs);
           }
           else{
                vector <point> H = getConvexHull(p);
                int sz = H.size();
                if(sz==3)
                {
                    printf("Case %d: 0\n",cs);
                    continue;
                }
                double mini=Angle(H[sz-2],H[0],H[1]);
                for(i=1;i<sz-1;i++)
                {
                    mini = min(mini, Angle(H[i-1] , H[i] , H[i+1]));
                }
                printf("Case %d: %lf\n",cs,mini);
           }
       }
       return 0;

}
