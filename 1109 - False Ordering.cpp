
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
#include <algorithm>
using namespace std;

struct abc
{
       int num,div;
}res[1005];

void pre()
{
       int i,j;

       for(i=1;i<=1000;i++)
       {
              int ct=0;
              for(j=1;j*j<=i;j++)
              {
                     if(i%j==0)
                     {
                            if(j!=(i/j)) ct+=2;
                            else ct+=1;
                     }
              }
              res[i].num=i;
              res[i].div+=ct;
       }
}
bool cmp(abc x,abc y)
{
       if(x.div==y.div) return x.num>y.num;
       return x.div<y.div;
}
int main()
{

    //freopen("in.txt", "r", stdin);
    pre();
    sort(res+1,res+1001,cmp);
    int cs,t,n;
    scanf("%d",&t);
    for(cs=1;cs<=t;cs++)
    {
            scanf("%d",&n);
            printf("Case %d: %d\n",cs,res[n].num);
    }



}
