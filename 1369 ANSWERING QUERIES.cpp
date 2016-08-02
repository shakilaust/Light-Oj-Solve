
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


long long int ans,a[100005],sum[100005];
int main()
{   int cs,t;
    scanf("%d",&t);
    for(cs=1;cs<=t;cs++)
    {
           int n,i,q,j;
           scanf("%d %d",&n,&q);
           ans=0;
           for(i=0;i<n;i++)
           {scanf("%lld",&a[i]);
              if(i) sum[i]=sum[i-1]+a[i];
              else sum[i]=a[i];

           }
          for(i=0;i<n;i++)  ans+=(((n-i-1)*a[i])-(sum[n-1]-sum[i]));

           printf("Case %d:\n",cs);
           while(q--)
           {      int in,x,v,prev;
                  scanf("%d",&in);
                  if(in) printf("%lld\n",ans);
                  else
                  {      long long int dif;
                         scanf("%d %d",&x,&v);
                         prev=a[x];
                         a[x]=v;
                         if(prev>a[x])
                         {
                                dif=prev-a[x];
                                ans+=(x*dif);
                                ans-=((n-x-1)*dif);
                         }
                         else
                         {
                                dif=a[x]-prev;
                                ans-=(x*dif);
                                ans+=((n-x-1)*dif);
                         }

                  }
           }
    }
   return 0;
}
