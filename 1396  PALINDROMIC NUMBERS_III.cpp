
 //BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopner soman boro
 Author :: Shakil Ahmed
.............AUST_CSE27.........
 prob   ::
 Type   ::
 verdict::
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>
#include <set>
#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <list>
#include <map>
#include <queue>
#include <sstream>
#include <utility>
#define pf(a) printf("%d\n",a)
#define pf2(a,b) printf("%d %d\n",a,b)
#define pfcs(cs,a) printf("Case %d: %d\n",cs,a)
#define sc(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
#define pi acos(-1.0)
#define ff first
#define LL long long
#define ss second
#define rep(i,n) for(i = 0; i < n; i++)
#define REP(i,n) for(i=n;i>=0;i--)
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define ROF(i,a,b) for(int i = a; i >= b; i--)
#define re return
#define QI queue<int>
#define SI stack<int>
#define pii pair <int,int>
#define MAX
#define MOD
#define INF 1<<30
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define memo(a,b) memset((a),(b),sizeof(a))
#define G() getchar()
#define MAX3(a,b,c) max(a,max(b,c))

double const EPS=3e-8;
using namespace std;


template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
char str[100005];
bool isPalindrome()
{
       int i,sz=strlen(str);
       for(i=0;i<sz/2;i++)
          if(str[i]!=str[sz-1-i]) return false;
       return true;
}
void solve()
{
       bool flag=true;
       int sz=strlen(str);
       if(sz%2)
       {
              if(str[sz/2]!='9') str[sz/2]=str[sz/2]+1;
              else
              {      int idx=sz/2;
                     str[idx]='0';
                     int i=1;
                     bool notok=true;
                     while((sz/2-i)!=-1 && notok)
                     {
                           if(str[idx-i]!='9')
                           {
                                  str[idx-i]=str[idx-i]+1;
                                  str[idx+i]=str[idx+i]+1;
                                  notok=false;
                           }
                           else
                           {
                                  str[idx-i]='0';
                                  str[idx+i]='0';
                                  i++;

                           }
                     }
                     if(notok)
                     {flag=false;
                     }
              }
       }
       else
       {
              int front=sz/2-1;
              int back=sz/2;
              bool notok=true;
              while(front!=-1 && notok)
              {
                     if(str[front]!='9')
                     {
                            str[front]=str[front]+1;
                            str[back]=str[back]+1;
                            notok=false;
                     }
                     else
                     {
                            str[front]='0';
                            str[back]='0';
                            front--;
                            back++;
                     }
              }
              if(notok) flag=false;
       }
       if(flag) printf("%s\n",str);
       else
       {
              int i;
              str[0]=str[sz]='1';
              str[sz+1]='\0';
              printf("%s\n",str);
       }

}
void notpalindrome()
{
       int sz=strlen(str),i;
       bool flag=true;
       if(sz%2)
       {      bool already_done=false;
              for(i=0;i<sz/2;i++)
              {
                     if(str[i]>str[sz-1-i]) already_done=true;
                     if(str[i]<str[sz-1-i] ) already_done=false;
                     str[sz-1-i]=str[i];
              }
              if(!already_done)
              {
                     if(str[sz/2]!='9') str[sz/2]=str[sz/2]+1;
                     else
                     {
                     int idx=sz/2;
                     str[idx]='0';
                     int i=1;
                     bool notok=true;
                     while((sz/2-i)!=-1 && notok)
                     {
                           if(str[idx-i]!='9')
                           {
                                  str[idx-i]=str[idx-i]+1;
                                  str[idx+i]=str[idx+i]+1;
                                  notok=false;
                           }
                           else
                           {
                                  str[idx-i]='0';
                                  str[idx+i]='0';
                                  i++;

                           }
                     }
                     if(notok)
                     {flag=false;
                     }
                     }
              }
       }
       else
       {
               bool already_done=false;
              for(i=0;i<sz/2;i++)
              {
                     if(str[i]>str[sz-1-i]) already_done=true;
                      if(str[i]<str[sz-1-i] ) already_done=false;
                     str[sz-1-i]=str[i];
              }
              if(!already_done)
              {
                     int front=sz/2-1;
              int back=sz/2;
              bool notok=true;
              while(front!=-1 && notok)
              {
                     if(str[front]!='9')
                     {
                            str[front]=str[front]+1;
                            str[back]=str[back]+1;
                            notok=false;
                     }
                     else
                     {
                            str[front]='0';
                            str[back]='0';
                            front--;
                            back++;
                     }
              }
              if(notok) flag=false;
              }
       }
       if(flag) printf("%s\n",str);
       else
       {
              int i;
              str[0]=str[sz]='1';
              str[sz+1]='\0';
              printf("%s\n",str);
       }

}
int main()
{

    //freopen("in.txt", "r", stdin);
   int cs,t;
   scanf("%d",&t);
   for(cs=1;cs<=t;cs++)
   {      printf("Case %d: ",cs);
          scanf("%s",str);
          if(isPalindrome()) solve();
          else notpalindrome();
   }


}
