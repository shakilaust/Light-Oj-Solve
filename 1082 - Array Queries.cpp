
#include <stdio.h>
#include <algorithm>
#define MAX 100005
#define max 100000000
using namespace std;
int A[MAX<<2],input[MAX];

void build(int lf,int rt,int idx){

        if(lf==rt){
                A[idx] = input[lf];
                return ;
        }
        int mid = (lf + rt) /2;

        build(lf,mid,2*idx);       // call left child
        build(mid+1,rt,2*idx + 1);  // call right child
        A[idx] = min(A[2*idx], A[2*idx+1]);// answer for current node is the sum of its children value
        //printf("Indx: %d  A[indx]=%d\n",idx,A[idx]);
}
int query(int lf,int rt,int indx,int x,int y)
{
   if(lf>=x && rt<=y) return A[indx];
   int mid=(lf+rt)/2;
   int res=max;
   if(x<=mid)
   res=min(res,query(lf,mid,2*indx,x,y));
   if(y>mid)
   res=min(res,query(mid+1,rt,2*indx+1,x,y));
   return res;

}
int main()
{
 int T;
 scanf("%d",&T);
 for(int kase=1;kase<=T;kase++)
 {
  int N,Q,I,J;
  scanf("%d %d",&N,&Q);
  for(int i=1;i<=N;i++) scanf("%d",&input[i]);
  build(1,N,1);
  printf("Case %d:\n",kase);
  while(Q--)
  {
   scanf("%d %d",&I,&J);
   printf("%d\n",query(1,N,1,I,J));
  }
 }
 return 0;
}
