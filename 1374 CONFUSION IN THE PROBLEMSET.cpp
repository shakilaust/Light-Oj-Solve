
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MAX 10000
using namespace std;
int a[MAX+5],b[MAX+5],cs;
void solve()
{   int i,n,check=1;
    memset(b,-1,sizeof(b));
    scanf("%d",&n);
    for(i=0;i<n;i++)
         scanf("%d",&a[i]);
    for(i=0;i<n;i++)
    {
        if(a[i]>=n)
        {
            check=0;
            break;
        }
        if(b[(n-1)-a[i]]==-1)
        {
            b[(n-1)-a[i]]=a[i];
        }
        else if(b[a[i]]==-1)
        {
            b[a[i]]=a[i];
        }
        else
        {
            check=0;
            break;
        }
    }
    if(check) printf("Case %d: yes\n",cs);
    else printf("Case %d: no\n",cs);

}
int main()
{
    //freopen("input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(cs=1;cs<=t;cs++)
    {
        solve();
    }
}
