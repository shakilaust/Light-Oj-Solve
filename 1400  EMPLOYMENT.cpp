
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
#define mem(a,n) memset(a,n,sizeof(a));

using namespace std;

template<class T> T abs(T x) {re x > 0 ? x : -x;}
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
vector <pii> l[210],r[210];
int p[110],i,j,m,t;
int R2L[210],L2R[210];

void stable_Marriage()
{
    mem(R2L,-1);
    mem(p,0);
    for(i=0;i<m;i++)
    {
        int man=i;
        while(man>=0)
        {
            int wom;
            while(1)
            {
                wom=l[man][p[man]++].first;
                if(R2L[wom]<0 || r[wom][man].second<r[wom][R2L[wom]].second) break;

            }
            int hubby=R2L[wom];
            R2L[L2R[man]=wom]=man;
            man=hubby;
        }
    }
}
int main()
{     //freopen("input.txt","r",stdin);
    int kase=1,a;
    cin>>t;
    while(t--)
    {
        cin>>m;
        for(i=0;i<=m;i++)
        {
            l[i].clear();
            r[i].clear();
        }
        for(i=0;i<m;i++)
          for(j=0;j<m;j++)
            {
                cin>>a;
                l[i].pb(mp(a-m-1,j));
            }
        for(i=0;i<m;i++)
      {
          for(j=0;j<m;j++)
            {
                cin>>a;
                r[i].pb(mp(a-1,j));
            }
   sort(r[i].begin(),r[i].end());
        }

        stable_Marriage();
        printf("Case %d:",kase++);
        for(i=0;i<m;i++)
        printf(" (%d %d)",i+1,L2R[i]+m+1);
        printf("\n");

    }
}
