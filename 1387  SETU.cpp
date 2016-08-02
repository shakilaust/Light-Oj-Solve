
#include <stdio.h>
#include <string.h>
int main()
{
int t,u;
scanf("%d",&t);
getchar();
for(u=1;u<=t;u++)
{
int n,value=0;

scanf("%d",&n);
getchar();
printf("Case %d:\n",u);
while(n--)
{ char str[100],str1[30];
gets(str);
int val;
sscanf(str,"%s %d",str1,&val);
if(str1[0]=='d')
value+=val;
else
printf("%d\n",value);
}
}
return 0;
}
