
#include <stdio.h>
#define max(a,b) a>=b?a:b
#define min(a,b) a<b?a:b
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        int x1,x2,y1,y2,a1,a2,b1,b2,n;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        a1=max(x1,x2);
        a2=min(x1,x2);
        b1=max(y1,y2);
        b2=min(y1,y2);
	    printf("Case %d:\n",i);
        scanf("%d",&n);
        while(n--)
        {
            int a,b;
            scanf("%d %d",&a,&b);
		if((a>=a2 && a<=a1) && (b>=b2 && b<=b1))
			printf("Yes\n");
		else
			printf("No\n");

        }

    }
	return 0;

}
