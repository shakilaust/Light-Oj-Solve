
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
#define INF 1<<30
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define memo(a,b) memset((a),(b),sizeof(a))
#define G() getchar()


using namespace std;


template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
int M;
struct matrix
{
       int mat[2][2];
};
matrix multiplication(matrix a,matrix b)
{
       matrix ans;
       int i,j,k;
       rep(i,2) rep(j,2)
       {
              ans.mat[i][j]=0;
              rep(k,2)
              ans.mat[i][j]=(ans.mat[i][j]%M+((a.mat[i][k])%M*(b.mat[k][j])%M)%M)%M;
       }
   return ans;
}
matrix matpow(matrix base,int p)
{
       if(p==1) return base;
       matrix x=matpow(base,p>>1);
       x=multiplication(x,x);
       if(p & 1) x=multiplication(x,base);
       return x;
}


int main()
{

    //freopen("in.txt", "r", stdin);
    int cs,T;
    sc(T);
    FOR(cs,1,T)
    {
           int a,b,n;
           cin>>a>>b>>n>>M;
           if(M==1) M=10; else if(M==2) M=100; else if(M==3) M=1000; else M=10000;
           matrix base,ans;
           base.mat[0][0]=base.mat[0][1]=base.mat[1][0]=1;
           base.mat[1][1]=0;
           ans=matpow(base,n-1);
           printf("Case %d: %d\n",cs,((b*ans.mat[0][0])%M+(a*ans.mat[0][1])%M)%M);
    }


}
