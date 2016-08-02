#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;
int a[55],b[55],cs;
void solve()
{
    int n,i,j,k,res=0;
    cin>>n;
    for(i=0;i<n;i++) cin>>a[i];
    for(i=0;i<n;i++) cin>>b[i];
    //for(i=0;i<n;i++) cout<<"I:: "<<b[i]<<endl;
    sort(a,a+n);
    sort(b,b+n);
    for(i=0;i<n;i++)
    {
          for(j=n-1;j>=0;j--)
          {
                if(a[i]>b[j] && b[j]!=-1)
                {
                    res+=2;
                    a[i]=-1;
                    b[j]=-1;
                    break;
                }
          }
    }
    for(i=0;i<n;i++)
       {
           if(a[i]!=-1)
              for(j=0;j<n;j++)
              {
                  if(a[i]==b[j] && b[j]!=-1)
                  {
                      res+=1;
                      b[j]=-1;
                      break;
                  }
              }
       }
    printf("Case %d: %d\n",cs,res);
 }
int main()
{
    int test;
    cin>>test;
    for(cs=1;cs<=test;cs++)
    {
        solve();
    }
}

