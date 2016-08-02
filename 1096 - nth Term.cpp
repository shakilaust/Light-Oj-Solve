
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
const int M = 10007;
struct matrix
{
       int mat[4][4];
};
matrix MatrixMultiplication(matrix a,matrix b)
{
            matrix ans;
            int i,j,k;
            for(i=0;i<4;i++)
                for(j=0;j<4;j++)
                {   ans.mat[i][j]=0;
                    for(k=0;k<4;k++)
                    {
                        ans.mat[i][j]=((ans.mat[i][j]%M)+(((a.mat[i][k]%M)*(b.mat[k][j]%M))%M))%M;
                    }

                }
            return ans;
}
matrix matPow(matrix BASE,int p)
{
            if(p==1) return BASE;
            matrix X=matPow(BASE,p/2);
            X=MatrixMultiplication(X,X);
            if(p&1)X=MatrixMultiplication(X,BASE);
            return X;
}
int main()
{  int cs,t;
   scanf("%d",&t);      matrix base;
                        base.mat[1][0]=1;
                        base.mat[1][1]=0;
                        base.mat[1][2]=0;
                        base.mat[1][3]=0;

                        base.mat[2][0]=0;
                        base.mat[2][1]=1;
                        base.mat[2][2]=0;
                        base.mat[2][3]=0;

                        base.mat[3][0]=0;
                        base.mat[3][1]=0;
                        base.mat[3][2]=0;
                        base.mat[3][3]=1;
   for(cs=1;cs<=t;cs++)
   {      int a,b,c,n;
          scanf("%d %d %d %d",&n,&a,&b,&c);
          if(n<=2)
          {
                 printf("Case %d: 0\n",cs);
                 continue;
          }

                        base.mat[0][0]=a;
                        base.mat[0][1]=0;
                        base.mat[0][2]=b;
                        base.mat[0][3]=1;


         matrix  ans=matPow(base,n-2);
          printf("Case %d: %d\n",cs,((ans.mat[0][3]%M)*(c%M))%M);
   }
   return 0;
}
