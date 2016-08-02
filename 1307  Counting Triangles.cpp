
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
int a[2005];
void solve()
{
       int i,j,k,n,res=0,t;
       scanf("%d",&n);
       for(i=0;i<n;i++) scanf("%d",&a[i]);
       sort(a,a+n);
       for(i=0;i<n;i++)
       {
            for(k=i+1;k<n-1;k++)
               {     if(a[k+1]>=a[i]+a[k]) continue;
                     if(a[n-1]<a[i]+a[k])
                     {
                            res+=(n-1-k);
                            continue;
                     }
                     int sum=a[i]+a[k],start=k+1,end=n-1,mid;
                             for(j=1;j<=12;j++)
                             {
                             mid=(start+end)/2;
                             if(sum>a[mid]) start=mid;
                             else end=mid;
                             }
                      res+=( mid-k);


               }
         }
               printf("%d\n",res);
}
int main()
{
       int cs,t;
       scanf("%d",&t);
       for(cs=1;cs<=t;cs++)
       {
              printf("Case %d: ",cs);
              solve();
       }

}
