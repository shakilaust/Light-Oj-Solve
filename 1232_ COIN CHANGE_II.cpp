
//BISMILLAHIRRAHMANIRRAHIM
/* Author :Shakil_AUST
   problem:
   Type   :
*/
#include <stdio.h>
#include <string.h>

int count( int S[], int m, int sum )
{
      int table[sum+1];

    memset(table, 0, sizeof(table));

    table[0] = 1;

    for(int i=0; i<m; i++)
        for(int j=S[i]; j<=sum; j++)
            table[j] = (table[j]+table[j-S[i]])%100000007;

    return table[sum];
}
int main()
{  int s[105],M,N,t;
   scanf("%d",&t);
   for(int kase=1;kase<=t;kase++)
   {
   scanf("%d %d",&M,&N);
   for(int i=0;i<M;i++)  scanf("%d",&s[i]);
   int res=count(s,M,N);
   printf("Case %d: %d\n",kase,res);
   }
   return 0;
}
