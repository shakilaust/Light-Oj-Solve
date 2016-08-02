
#include <stdio.h>
int main()
{
    int T,j,a[40];
    scanf("%d",&T);
    for(j=1; j<=T; j++)
    {
        int n,p,m,i,sum=0,r=0;
        scanf("%d %d %d",&n,&p,&m);
        for(i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            if((i<=p )&&((sum+a[i])<=m))
            {
                r=i;
                sum+=a[i];
            }
        }
        printf("Case %d: %d\n",j,r);
    }
    return 0;
}
