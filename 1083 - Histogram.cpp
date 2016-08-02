
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
#define max(a,b) a>b?a:b
#define MAX 30010
#define sc scanf
#define pf printf
int main()
{  long long int t,n,histrogram[MAX],left[MAX],right[MAX];
   sc("%lld",&t);
   for(int kase=1;kase<=t;kase++)
   {  sc("%d",&n);
      for(int i=1;i<=n;i++)
      sc("%lld",&histrogram[i]);
      stack <long long int> q;
      q.push(0);
      histrogram[0]=0;
      for(int i=1;i<=n;i++)
      {
         while(histrogram[q.top()]>=histrogram[i])
         q.pop();
         left[i]=q.top()+1;
         q.push(i);
      }
      while(!q.empty())
      q.pop();
      q.push(n+1);
      histrogram[n+1]=0;
       for(int i=n;i>0;i--)
      {
         while(histrogram[q.top()]>=histrogram[i])
         q.pop();
         right[i]=q.top()-1;
         q.push(i);
      }
      long long int res=-1;
      for(int i=1;i<=n;i++)
        res=max(res,(right[i]-left[i]+1)*histrogram[i]);
      pf("Case %d: %lld\n",kase,res);


   }
   return 0;

}
