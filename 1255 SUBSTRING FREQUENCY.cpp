
//BISMILLAHIRRAHMANIRRAHIM
/* Author :Shakil_AUST
   problem:
   Type   :
*/

#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
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
#define LL long long
#define ff first
#define ss second
#define rep(i,n) for(int i = 0; i < n; i++)
#define REP(i,n) for(int i=n;i>=0;i--)
#define ROF(i,a,b) for(int i = a; i <= b; i++)
#define rof(i,a,b) for(int i = a; i >= b; i--)
#define re return
#define QI queue<int>
#define SI stack<int>
#define pii pair <int,int>
#define MAX 1000005
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))

using namespace std;

template<class T> T abs(T x) {re x > 0 ? x : -x;}
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
int T[MAX];
string A,B;
int lenA,lenB;
vector <int> shift;
void init()
{  rep(i,lenA+5) T[i]=0;
}
void ComputePrefixFunction()
{  int k=0,q;
   T[1]=0;
   for(q=2;q<=lenB;q++)
   {  while (k>0 && B[k]!=B[q-1]) k=T[k];
         if(B[k]==B[q-1]) k++;
         T[q]=k;
   }
}
 void KMP_Matcher()
 {  int q=0;
    ComputePrefixFunction();
    rep(i,lenA)
        {   while( q>0 && B[q]!=A[i]) q=T[q];
           if(B[q]==A[i]) q++;
         if(q==lenB) { shift.pb(1+i-lenB); q=T[q];}
        }

 }
int main()
{    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
        int test;
        cin>>test;
        ROF(kase,1,test)
        {  cin>>A>>B;
           lenA=A.size();
           lenB=B.size();
           shift.clear();
           init();
           KMP_Matcher();
           printf("Case %d: %d\n",kase,shift.size());
        }



    return 0;
}
