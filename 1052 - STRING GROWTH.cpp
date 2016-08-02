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

#define II ( { int a ; read(a) ; a; } )
#define LL ( { Long a ; read(a) ; a; } )

using namespace std;



typedef long long Long;



//Fast Reader
template<class T>inline bool read(T &x){int c=getchar();int sgn=1;while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}for(x=0;~c&&'0'<=c&&c<='9';c=getchar())x=x*10+c-'0'; x*=sgn; return ~c;}

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

/* **************************************  My code start here ****************************************** */

const Long mod = ( 1000000007);

struct Matrix
{
    Long mat[2][2];
};

Matrix unit , base ;

Long fibo[ 55 ] ;

int n , m , k , nlen , mlen ;

void ini()
{
    fibo[0] = 1 ;
    fibo[1] = 0 ;
    for ( int i = 2 ; i < 48 ; i++ ) fibo[ i ] = fibo[ i - 1 ] + fibo[ i - 2 ];
}

Matrix Multiplication( Matrix A , Matrix B )
{
    Matrix ans ;
    for ( int i = 0 ; i < 2 ; i++ )
    {
        for ( int j = 0 ; j < 2 ; j++ )
        {
            ans.mat[i][j] = 0 ;
            for ( int k = 0 ; k < 2 ; k++ )
            {
                ans.mat[i][j] += ( A.mat[i][k] * B.mat[k][j] );
                ans.mat[i][j] %= mod ;
            }
        }
    }
    return ans ;
}

Matrix Pow( int p , Matrix base )
{
    if( p == 0 ) return unit ;
    if( p == 1 ) return base ;
    Matrix X = Pow( p / 2 , base );
    X = Multiplication( X , X );
    if( p & 1 ) X = Multiplication( X , base );
    return X ;


}
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being


     unit.mat[0][0] = unit.mat[1][1] = base.mat[0][0] = 1 ;
     base.mat[0][1] = base.mat[1][0] = 1 ;
     base.mat[1][1] = unit.mat[0][1] = unit.mat[1][0] = 0 ;
     ini();
     int cs , t = II ;
     for ( cs = 1 ; cs <= t ; cs++ )
     {
         n = II , nlen = II , m = II , mlen = II , k = II ;
         if( n > 46 || m > 46 ) // as the value will be more then mod we can determine result
         {
             printf("Case %d: Impossible\n",cs);
             continue ;
         }
         Long a1 = fibo[ n + 1 ] , b1 = fibo[ n + 2 ] , c1 = -nlen ;
         Long a2 = fibo[ m + 1 ] , b2 = fibo[ m + 2 ] , c2 = -mlen ;
         Long d = a1 * b2 - a2 * b1 ;
         Long dx = b1*c2 - b2*c1 ;
         Long dy = a2*c1 - a1*c2 ;
         if( d == 0 || dx/d < 0 || dy/d < 0 || dx%d || dy%d )
         {
              printf("Case %d: Impossible\n",cs);
              continue ;
         }

         Long a = dx/d ;
         Long b = dy/d ;
         Matrix Ans = Pow( k , base );

         Long ans = ( (Ans.mat[1][0] * a) % mod + (Ans.mat[0][0] * b )%mod) % mod ;

         printf("Case %d: %lld\n",cs,ans);


     }

    return 0;
}
