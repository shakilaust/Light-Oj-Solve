
#include <stdio.h>
#include <string.h>
int main()
{
int n,i;
scanf("%d",&n);
getchar();
for(i=1;i<=n;i++)
{ char str1[50],str2[50];
long long int y1,y2,count=0;
int d1,d2;
scanf("%s %d, %lld",str1,&d1,&y1);
scanf("%s %d, %lld",str2,&d2,&y2);
count=((y2/4)-(y2/100)+(y2/400))-((y1/4)-(y1/100)+(y1/400));
if( ((y1%4==0 && y1%100!=0) || y1%400==0) &&(strcmp(str1,"January")==0 || strcmp(str1,"February")==0))
count+=1;
if( ((y2%4==0 && y2%100!=0) || y2%400==0) &&(strcmp(str2,"January")==0 || strcmp(str2,"February")==0))
{
if(strcmp(str2,"February")==0&&d2==29)
int rp=10; //just nothing....

else
count-=1;
}

if(y1==y2)
{ if((strcmp(str1,"January")==0 || strcmp(str1,"February")==0 ))
if((strcmp(str2,"January")!=0 && strcmp(str2,"February")!=0) || (strcmp(str2,"February")==0 && d2==29))
if((y1%4==0 && y1%100!=0) || y1%400==0)
count=1;
}


printf("Case %d: %lld\n",i,count);
}
return 0;

}
