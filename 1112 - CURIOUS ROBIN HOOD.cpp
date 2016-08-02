// LIght oj 1112
// BISMILLAHIRRAHMANIRRAHIM
#include <stdio.h>
#include <algorithm>
#define MAX 100005
using namespace std;
int A[MAX<<2];
void build(int lf,int rt,int node)
{
    if(lf==rt)
    {
        scanf("%d",&A[node]);
        return;
    }
    int mid=(lf+rt)>>1;
    build(lf,mid,node<<1);
    build(mid+1,rt,(node<<1)+1);
    A[node]=A[node<<1]+A[(node<<1)+1];
}
int query(int lf,int rt,int node,int x,int y)
{
    if(x>rt || y<lf) return 0;
    if(x<=lf && y>=rt) return A[node];
    int mid=(lf+rt)>>1;
     int ret=0;
    if(x<=mid) ret+=query(lf,mid,node<<1,x,y);
    if(y>mid) ret+=query(mid+1,rt,(node<<1)+1,x,y);
    return ret;
}
void update(int lf,int rt,int node,int x,int val)
{
   // if(x>rt || y<lf || lf>rt) return;
    if(lf==rt)
    {
        A[node]+=val;
        return ;
    }
    int mid=(lf+rt)>>1;
    if(x<=mid)
        update(lf,mid,node<<1,x,val);
    else
        update(mid+1,rt,(node<<1)+1,x,val);
    A[node]=A[node<<1]+A[(node<<1)+1];
}
int main()
{
    int cs,t;
    scanf("%d",&t);
    for(cs=1; cs<=t; cs++)
    {   printf("Case %d:\n",cs);
        int n,i,q;
        scanf("%d %d",&n,&q);
     //   for(i=1; i<=n; i++) scanf("%d",&input[i]);
        build(1,n,1);
        while(q--)
        {
            int a,b,c;
            scanf("%d %d",&a,&b);
            if(a==1)
            {   b++;
                int ans=query(1,n,1,b,b);
                update(1,n,1,b,-ans);
                printf("%d\n",ans);
            }
            else if(a==2)
            {
                scanf("%d",&c);
                b++;
                update(1,n,1,b,c);
            }
            else
            {
                scanf("%d",&c);
                if(b>c) swap(b,c);
                b++,c++;
                int ans=query(1,n,1,b,c);
                printf("%d\n",ans);

            }
        }
    }
}

