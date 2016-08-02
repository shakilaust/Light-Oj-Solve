
#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
    int test,cs=1;
    scanf("%d",&test);
    while(test--)
    {
        int N,W;
        scanf("%d %d",&N,&W);
        int a[N+1],faofao,i,u,res=1;
        for(i=0;i<N;i++)
           scanf("%d %d",&faofao,&a[i]);
        sort(a,a+N);
        u=a[0];
        for(i=1;i<N;i++)
        {
            if(a[i]>u+W)
            {
                u=a[i];
                res++;
            }
        }
        printf("Case %d: %d\n",cs++,res);
    }
}
