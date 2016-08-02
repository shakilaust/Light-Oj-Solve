#include <stdio.h>
#define max(a,b) a>=b?a:b
#define min(a,b) a<b?a:b
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        int a,b,c,k;
        scanf("%d %d %d",&a,&b,&c);
        if(a>c)
        {
            if(a>b)
            {
                k=a;
                a=c;
                c=k;
            }
            else
            {
                k=b;
                b=c;
                c=k;
            }
        }
        else if(b>c)
        {
            if(b>a)
            {
                k=c;
                c=b;
                b=k;
            }
            else
            {
                k=a;
                a=c;
                c=k;
            }
        }
        if((c*c)==(a*a)+(b*b))
        printf("Case %d: yes\n",i);
        else
        printf("Case %d: no\n",i);

    }
    return 0;

}
