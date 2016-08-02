
#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#define  pb push_back
using namespace std;
string A,B;
vector <int> T,pos;
void build_failure_function()
{
   T = vector <int> (B.size());
  int i = 2, j = 0;
  T[0] = -1; T[1] = 0;

  while(i < B.length())
  {
    if(B[i-1] ==B[j]) { T[i] = j+1; i++; j++; }
    else if(j > 0) j = T[j];
    else { T[i] = 0; i++; }
  }
}
int KMP()
{
    int i,j=0;
    build_failure_function();
    for(i=0;i<A.size();i++)
    {
        while(j>0 && B[j]!=A[i]) j=T[j];
        if(A[i]==B[j]) j++;
        if(j==B.size()) break;
    }
  return j;
}
void solve()
{
    cin>>A;
    B=A;
    reverse(B.begin(),B.end());
    int res=KMP();
    if(res==0)
    {
        if(A.size()%2) res+=(2*A.size())-1;
        else res+=(2*A.size());
    }
    else
    {
        res=(A.size()-res)+A.size();
    }
    cout<<res<<endl;
}
int main()
{
   int t,kase=1;
   for(scanf("%d",&t);kase<=t;kase++)
   {
       printf("Case %d: ",kase);
       solve();
   }
}
