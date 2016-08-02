
#include <stdio.h>
#include <algorithm>
#define MAX 100005
#define  Inf 1<<28
using namespace std;
int Min[MAX<<2],Max[MAX<<2],input[MAX];

void build(int lf,int rt,int idx){

        if(lf==rt){
                Min[idx] = input[lf];
                Max[idx]=Min[idx];

                return ;
        }
        int mid = (lf + rt) /2;

        build(lf,mid,2*idx);       // call left child
        build(mid+1,rt,2*idx + 1);  // call right child
        Min[idx] = min(Min[2*idx], Min[2*idx+1]);
        Max[idx]=max(Max[2*idx],Max[2*idx+1]);
}
int Min_query(int lf,int rt,int indx,int x,int y)
{
   if(lf>=x && rt<=y) return Min[indx];
   int mid=(lf+rt)/2;
   int res=Inf;
   if(x<=mid)
   res=min(res,Min_query(lf,mid,2*indx,x,y));
   if(y>mid)
   res=min(res,Min_query(mid+1,rt,2*indx+1,x,y));
   return res;

}int Max_query(int lf,int rt,int indx,int x,int y)
{
   if(lf>=x && rt<=y) return Max[indx];
   int mid=(lf+rt)/2;
   int res=-Inf;
   if(x<=mid)
   res=max(res,Max_query(lf,mid,2*indx,x,y));
   if(y>mid)
   res=max(res,Max_query(mid+1,rt,2*indx+1,x,y));
   return res;

}

int main()
{
 int T;
 scanf("%d",&T);
 for(int kase=1;kase<=T;kase++)
 {
  int N,Q;
  scanf("%d %d",&N,&Q);
  for(int i=0;i<N;i++) scanf("%d",&input[i]);
  build(0,N-1,1);
  int ans=-1;
  for(int i=0;i<=N-Q;i++)
  ans=max(ans,abs((Max_query(0,N-1,1,i,i+Q-1))-Min_query(0,N-1,1,i,i+Q-1)));
  printf("Case %d: %d\n",kase,ans);

 }
 return 0;
}
