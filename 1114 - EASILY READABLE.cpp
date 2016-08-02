
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <algorithm>
using namespace std;
#define rep(i,n) for(i=0;i<n;i++)
int trie[100005][53];
char str[100005],word[100005];
int idx;
int value(char ch)
{
       if(isupper(ch)) return ch-'A';
       return ch-'a'+26;
}
void insert(char *str)
{
       int cur=0,i;
       for(i=0;str[i];i++)
       {
              int j=value(str[i]);
              if(trie[cur][j]==-1)
              {
                     trie[cur][j]=++idx;
                     memset(trie[idx],-1,sizeof(trie[idx]));
                     trie[idx][52]=0;

              }
              cur= trie[cur][j];
       }
       trie[cur][52]+=1;
}
int travers(char *str)
{
       int cur=0,i;
       for(i=0;str[i];i++)
       {
              int j=value(str[i]);
              if(trie[cur][j]==-1)
              {
                     return 0;
              }
              cur= trie[cur][j];
       }
       return trie[cur][52];

}

int main()
{
       int cs,t,i,n,j;
       scanf("%d",&t);
       for(cs=1;cs<=t;cs++)
       {      idx=0;
              memset(trie[0],-1,sizeof(trie[0]));
              trie[0][52]=0;
              scanf("%d",&n);
              rep(i,n)
              {
                     scanf("%s",str);
                     if(strlen(str)>2) sort(str+1,str+strlen(str)-1);
                     insert(str);
              }
              scanf("%d",&n);
              getchar();
              printf("Case %d:\n",cs);
              rep(j,n)
              {      int res=1;
                     gets(str);
                     for(i=0;str[i];i++)
                     {
                            if(!isalpha(str[i])) continue;
                            int j=0;
                            while(str[i] && isalpha(str[i])) word[j++]=str[i++];
                            i--;
                            word[j]='\0';
                            if(j>2) sort(word+1,word+j-1);
                            res*=travers(word);

                     }
                     printf("%d\n",res);
              }
       }
}
