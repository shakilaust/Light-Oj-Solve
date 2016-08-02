
#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int main()
{ int n;
cin>>n;
cin.ignore(100,'\n');
for(int i=1;i<=n;i++)
{
string str;
int r;
cin>>r;
cin.ignore(100,'\n');
getline(cin,str);
int k=0,val=0;
for(int j=0,sz=str.size();j<sz;j++)
{
if(str[j]=='.')
{
k++;
if(k==3)
{
val+=1;
k=0;
}

}
else
{ if(k==2)
{
val+=1;
k=0;
}
if(k==1 && (str[j+1]=='.' || str[j+1]=='#'))
{
val+=1;
k=0;
j++;
}
}
}
if(k>0)
val+=1;
printf("Case %d: %d\n",i,val);
}
return 0;
}
