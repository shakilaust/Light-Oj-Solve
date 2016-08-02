
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
#include <algorithm>
#define rep(i,n) for(i = 0; i < n; i++)
#define memo(a,b) memset((a),(b),sizeof(a))



using namespace std;



struct marriage
{
       int hight,age,state;
}man[55],woman[55];
int n,m;
bool seen[105];
int adj[55][55],deg[55],Right[105],mx;
bool bmp(int u)
{
       int i;
       for(i=0;i<deg[u];++i)
       {
              int v=adj[u][i];
              if(seen[v]) continue;
              seen[v]=1;
              if(Right[v]==-1 || bmp(Right[v]))
              {
                     Right[v]=u;
                     return true;
              }
       }
       return false;
}
int bipertilematching()
{
       int i,cnt=0;
       memset(seen,0,(mx+2)*sizeof(bool));
       memset(Right,-1,(mx+2)*sizeof(int));
       for(i=0;i<m;i++)
       {
              if(bmp(i))
              {
                     cnt++;
                     memset(seen,0,(mx+2)*sizeof(bool));

              }
       }
       return cnt;
}
int main()
{
       int cs,t,i,j;
       scanf("%d",&t);
       for(cs=1;cs<=t;cs++)
       {
              scanf("%d %d",&m,&n);
              mx=0;
              rep(i,m) scanf("%d %d %d",&man[i].hight,&man[i].age,&man[i].state);
              rep(i,n) scanf("%d %d %d",&woman[i].hight,&woman[i].age,&woman[i].state);

              memo(deg,0);
              rep(i,m)
                 rep(j,n)
                 {
                        if(abs(man[i].hight-woman[j].hight)<=12 && abs(man[i].age-woman[j].age)<=5 && man[i].state==woman[j].state)
                         {
                                adj[i][deg[i]++]=(m+j);
                               // printf("%d %d\n",i,m+j);
                               if((m+j)>mx) mx=m+j;
                         }

                 }
              printf("Case %d: %d\n",cs,bipertilematching());

       }
}
