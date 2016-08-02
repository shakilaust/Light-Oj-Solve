
#include <stdio.h>
#include <string.h>
#include <vector>
#define ll long long
#define pb push_back
using namespace std;

vector <int> prime;

bool flag[100000+5],check[60000];

void seive()
{
	int i,j;
	prime.pb(2);
	for(i=3;i*i<=50000;i+=2)
	{
		if(check[i]==0)
		{   prime.pb(i);
			for(j=(i*i);j<=50000;j+=(2*i))
				check[j]=1;
		}
	}
	for(;i<=50000;i+=2) if(check[i]==0) prime.pb(i);

}

int cal(ll a,ll b)
{   int i,ans=0;

	 for(i=0;i<(b-a+1);i++) flag[i]=0;
       if(a<2) a=2;
	for(i=0;(ll) (prime[i]* prime[i])<=b && i<prime.size() ;i++)
		{
            ll j=(prime[i] * (a/prime[i]));
            if(j<a)
            	j+=prime[i];
            if(j<(ll)(prime[i]+prime[i])) j=prime[i]+prime[i];
            for(;j<=b;j+=prime[i]) flag[j-a]=1;
        }
     for(i=0;i<(b-a+1);i++)
     {
     	 if(flag[i]==0)
     	 {
     	 	ans++;
     	 }

     }
     return ans;
}

int main()
{       	seive();
	//printf("after seive\n");
	int cs,t;
	scanf("%d",&t);
	for(cs=1;cs<=t;cs++)
	{
          ll a,b;
          scanf("%lld %lld",&a,&b);
          //if(b<2) printf("Case %d: 0\n",cs);
          //else if(b==2) printf("Case %d: 1\n",cs);
         // else
          printf("Case %d: %d\n",cs,cal(a,b));

	}
}
