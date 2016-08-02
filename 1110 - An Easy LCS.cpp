#include <iostream>
#include <string>
#define MAXN 105
using namespace std;
string s1,s2,s[MAXN][MAXN];
string lex_min(string a,string b)
{
    if(a=="") return b;
    if(b=="") return a;
    if(a.size()>b.size()) return a;
    if(b.size()>a.size()) return b;
    if(a>b) return b;
    else return a;
}
int main()
{   int t,kase,i,n,m,j;
    cin>>t;
    for(kase=1;kase<=t;kase++)
    {
        cin>>s1>>s2;
        n=s1.size();
        m=s2.size();
        for(i=1;i<=n;i++)
          for(j=1;j<=m;j++)
             s[i][j]="";
        for(i=1;i<=n;i++)
           for(j=1;j<=m;j++)
              if(s1[i-1]==s2[j-1])
              s[i][j]=lex_min(s[i][j],s[i-1][j-1]+s1[i-1]);
              else
              s[i][j]=lex_min(s[i][j],lex_min(s[i-1][j],s[i][j-1]));
        cout<<"Case "<<kase<<": ";
        if(s[n][m]=="") cout<<":(\n";
        else cout<<s[n][m]<<endl;
    }

}
