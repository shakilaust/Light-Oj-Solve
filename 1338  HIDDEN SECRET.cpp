
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char str[110],str1[110];
    int i,n;
    scanf("%d\n",&n);
    for(i=1;i<=n;i++)
    {
       gets(str);
       gets(str1);
       int sum=0,j,k,sum1=0;
       j=strlen(str);
       for(k=0;str[k];k++)
        str[k]=tolower(str[k]);
       for(k=0;k<j;k++)
          if(str[k]!=' ')
          sum+=str[k];
      j=strlen(str1);
      for(k=0;str1[k];k++)
        str1[k]=tolower(str1[k]);
        for(k=0;k<j;k++)
        if(str1[k]!=' ')
          sum1+=str1[k];
        if(sum==sum1)
        printf("Case %d: Yes\n",i);
        else
        printf("Case %d: No\n",i);
    }
    return 0;

}
