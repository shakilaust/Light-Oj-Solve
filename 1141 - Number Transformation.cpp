
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <algorithm>
#include <vector>
#define pb push_back
using namespace std;

bool check[2000];
vector <int> prime_factor[2000],prime;
int cost[2000],S,T,cs;
void clear()
{   prime.clear();
    int i;
    for(i=1;i<=1000;i++) prime_factor[i].clear();
}
void ini()
{
    clear();
    int i,j,k;
    memset(check,true,sizeof(check));
    check[0]=check[1]=false;
    for(i=4;i<=100;i+=2) check[i]=false;
    for(i=3;i*i<=1000;i+=2)
    {
        if(check[i])
        for(j=i*i;j<=1000;j+=(2*i))
        check[j]=false;
    }
    prime.pb(2);
    for(i=3;i<=1000;i+=2)
    {
        if(check[i]) prime.pb(i);
    }
    for(i=2;i<=1000;i++)
    {   int num=i,sq=sqrt(i);
        for(j=0;prime[j]<=sq  && j<prime.size();j++)
        {
            if(num%prime[j]==0)
            prime_factor[i].pb(prime[j]);
            while(num%prime[j]==0)
            num/=prime[j];
        }
        if(num>1 && num!=i) prime_factor[i].pb(num);
    }

}
int bfs()
{
    queue<int> q;
    q.empty();
    q.push(S);
    if(S==T) return 0;
    if(S>T)  return -1;
    int i;
    for(i=0;i<=T+1;i++) cost[i]=0;
    while(!q.empty())
    {
        int v=q.front();
        if(v>1000) return -1;
        q.pop();

        for(i=0;i<prime_factor[v].size();i++)
        {
            int u=prime_factor[v][i];
            if(v+u<=T && !cost[v+u])
            {   cost[v+u]=cost[v]+1;
                if(v+u==T) return cost[v+u];
                q.push(v+u);
            }
        }
    }
    return -1;
}
void solve()
{
   scanf("%d %d",&S,&T);
   printf("Case %d: %d\n",cs,bfs());

}
int main()
{   int t;
    ini();
    scanf("%d",&t);
    for(cs=1;cs<=t;cs++) solve();
}
