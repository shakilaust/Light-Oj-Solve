
//BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopenr soman boro
 Author :: Shakil Ahmed
 prob   ::
 Type   ::
 verdict::
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
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
#define pf printf
#define sc scanf
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
#define MAX 1000000
#define INF 1<<29
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))

using namespace std;

template<class T> T abs(T x) {re x > 0 ? x : -x;}
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
int N,in[105][105],i,j,k;
void clear()
{
    for(i=0;i<N;i++)
       for(j=0;j<N;j++)
          if(i==j) in[i][j]=0;
          else in[i][j]=INF;
}

int FloydWarshall()
{
    for(k=0;k<N;k++)
       for(i=0;i<N;i++)
          for(j=0;j<N;j++)
             in[i][j]=min(in[i][j],in[i][k]+in[k][j]);
}


int main()
{   // freopen("input.txt","r",stdin);
    int t,kase=1;
    for(scanf("%d",&t);kase<=t;kase++)
    {   int R,u,v,S,D;
        scanf("%d",&N);
        scanf("%d",&R);
        clear();
        while(R--)
        {
            scanf("%d %d",&u,&v);
            in[u][v]=in[v][u]=1;
        }
        scanf("%d %d",&S,&D);
        FloydWarshall();
        int MIN=in[S][0]+in[0][D];
        for(i=1;i<N;i++)
        MIN=max(MIN,in[S][i]+in[i][D]); //ekhane max korteche karon sobaike pochaite hobe
        printf("Case %d: %d\n",kase,MIN);
    }

}
