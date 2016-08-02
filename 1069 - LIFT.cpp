
//BISMILLAHIRRAHMANIRRAHIM
// Problem C
#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
       int cs,t,pos,lift;
       scanf("%d",&t);
       for(cs=1;cs<=t;cs++)
       {
              scanf("%d %d",&pos,&lift);
              int res=abs(pos-lift)*4+pos*4+19;
              printf("Case %d: %d\n",cs,res);
       }
}
