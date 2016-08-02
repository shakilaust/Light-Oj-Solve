
// BISMILLAHIRRAHMANIRRAHIM
#include <stdio.h>
#include <string.h>
#define MaxVal 100005
int tree[MaxVal];
char input[MaxVal],ch;
int read(int idx)
{
       int sum=0;
       while(idx>0)
       {
              sum+=tree[idx];
              idx-=(idx & -idx);
       }
      return sum;
}
void update(int idx,int val)
{
       while(idx<=MaxVal)
       {
              tree[idx]+=val;
              idx+=(idx & -idx);
       }
}
int main()
{
       int cs,t,q;
       scanf("%d",&t);
       for(cs=1;cs<=t;cs++)
       {      printf("Case %d:\n",cs);
              memset(tree,0,sizeof(tree));
              scanf("%s",input);
             // printf("%s\n",input);
              scanf("%d",&q);
              getchar();
             // printf("q:: %d\n",q);
              while(q--)
              {
                     int x,y;
                     scanf("%c",&ch);
                    // getchar();
                   //printf("ch:: %c\n",ch);
                     if(ch=='I')
                     {
                            scanf("%d %d",&x,&y);
                            getchar();
                            //printf("x:: %d    y:: %d\n",x,y);
                            update(x,1);

                            update(y+1,-1);
                     }
                     else
                     {
                            scanf("%d",&x);
                            getchar();
                            int ans=read(x);
                            if(ans%2) // odd bar already update hoiche
                            {
                                   printf("%d\n",input[x-1]=='1'?0:1);
                            }
                            else
                            printf("%c\n",input[x-1]);
                     }
              }

       }
}
