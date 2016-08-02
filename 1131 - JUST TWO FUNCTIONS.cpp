
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
#define MAX3(a,b,c) max(a,max(b,c))

double const EPS=3e-8;
using namespace std;
const int N = 6 ;
LL Ans1 , Ans2 , a[3], b[3], c[3], g[3], f[3], M;

struct matrix
{
       int mat[N][N];
};
matrix MatrixMultiplication(matrix a,matrix b)
{
            matrix ans;
            int i,j,k;
            for(i = 0 ; i < N  ; i++ )
                for(j = 0 ; j< N ; j++ )
                {   ans.mat[i][j]=0;
                    for(k = 0 ; k < N ; k++ )
                    {
                        ans.mat[i][j]=((ans.mat[i][j])+(((a.mat[i][k])*(b.mat[k][j]))%M))%M;
                    }

                }
            return ans;
}
matrix matPow(matrix BASE,int p)
{
            if(p == 1) return BASE;
            matrix X = matPow( BASE, p/2);
            X = MatrixMultiplication( X, X);
            if(p&1) X = MatrixMultiplication ( X, BASE );

            return X;
}
 matrix base;

 void Pre()
 {
       base.mat[1][0] = 1;
       base.mat[2][1] = 1;
       base.mat[4][3] = 1;
       base.mat[5][4] = 1;
       base.mat[0][2] = base.mat[0][3] = base.mat[0][4] = 0;
       base.mat[3][0] = base.mat[3][1] = base.mat[3][5] = 0;
       base.mat[1][1] = base.mat[1][2] = base.mat[1][3] = base.mat[1][4] = base.mat[1][5] = 0;
       base.mat[2][0] = base.mat[2][2] = base.mat[2][3] = base.mat[2][4] = base.mat[2][5] = 0;
       base.mat[4][0] = base.mat[4][1] = base.mat[4][2] = base.mat[4][4] = base.mat[4][5] = 0;
       base.mat[5][0] = base.mat[5][1] = base.mat[5][2] = base.mat[5][3] = base.mat[5][5] = 0 ;
 }

 void input()
 {
        scanf("%lld %lld %lld",&a[1], &b[1], &c[1]);
        scanf("%lld %lld %lld",&a[2], &b[2], &c[2]);
        scanf("%lld %lld %lld",&f[0], &f[1], &f[2]);
        scanf("%lld %lld %lld",&g[0], &g[1], &g[2]);
        scanf("%lld",&M);

       base.mat[0][0] = a[1];
       base.mat[0][1] = b[1];
       base.mat[0][5] = c[1];
       base.mat[3][2] = c[2];
       base.mat[3][3] = a[2];
       base.mat[3][4] = b[2];
 }
 void solve() {
        int q,i,n ;
        scanf("%d",&q);
        for ( i = 0 ; i < q ; i++)
        {
               scanf("%d",&n);
               if(n<=2)
               {
                      Ans1 = ( f[n] ) % M ;
                      Ans2 = ( g[n] ) % M ;
               }
               else
               {
                            matrix  ans = matPow(base,n-2);
                            Ans1 = ( ( ans.mat[0][0] * f[2] ) % M + ( ans.mat[0][1] * f[1] ) % M + ( ans.mat[0][5] * g[0] ) %M + (ans.mat[0][2] * f[0])%M + ( ans.mat[0][3] * g[2])%M + (ans.mat[0][4] * g[1] ) % M ) %M ;
                            Ans2 = ( ( ans.mat[3][2] * f[0] ) % M + ( ans.mat[3][3] * g[2] ) % M + ( ans.mat[3][4] * g[1]) % M + (ans.mat[3][0] * f[2]) %M + ( ans.mat[3][1] * f[1]) %M + ( ans.mat[3][5] * g[0]) %M ) %M ;
               }
               printf("%lld %lld\n",Ans1,Ans2 );
        }
 }

int main()
{  int cs,t;
   Pre();

   scanf("%d",&t);
   for(cs=1;cs<=t;cs++)
   {

                       input();
                       printf("Case %d:\n",cs);
                       solve();
   }
   return 0;
}
