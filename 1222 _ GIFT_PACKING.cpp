
 //BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopner soman boro
 Author :: Shakil Ahmed
.............AUST_CSE27.........
 prob   ::
 Type   ::
 verdict::
 */
#include <bits/stdc++.h>

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
#define INF 1<<28
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define memo(a,b) memset((a),(b),sizeof(a))
#define G() getchar()
#define MAX3(a,b,c) max(a,max(b,c))

double const EPS=3e-8;
using namespace std;
const int N=55;

bool S[N],T[N];
int xy[N],yx[N];
int lx[N],ly[N],cost[N][N];
int q[100005],n,max_match;
int prev[N],slack[N],slackx[N];
void ini()
{
       int x,y;
       memo(lx,0);
       memo(ly,0);
       for(x=0;x<n;x++)
          for(y=0;y<n;y++) lx[x]=max(lx[x],cost[x][y]);
}
void Update()
{
       int x,y,delta=INF;
       for(y=0;y<n;y++) if(!T[y]) delta=min(delta,slack[y]);
       for(x=0;x<n;x++) if(S[x]) lx[x]-=delta;
       for(y=0;y<n;y++) if(T[y]) ly[y]+=delta;
       for(y=0;y<n;y++) if(!T[y]) slack[y]-=delta;
}
void Adjust(int x,int prevx)
{      int y;
       S[x]=1;
       prev[x]=prevx;
       for(y=0;y<n;y++)
       {
              if(lx[x]+ly[y]-cost[x][y]<slack[y])
              {
                     slack[y]=lx[x]+ly[y]-cost[x][y];
                     slackx[y]=x;
              }
       }
}
void agument()
{
       if(n==max_match) return ;
       int x,y,root,wr=0,rd=0;
       memo(S,0);
       memo(T,0);
       memo(prev,-1);
       for(x=0;x<n;x++)
       {
              if(xy[x]==-1)
              {      q[wr++]=root=x;
                     S[x]=1;
                     prev[x]=-2;
                     break;
              }
       }
       for(y=0;y<n;y++)
       {
              slack[y]=lx[root]+ly[y]-cost[x][y];
              slackx[y]=root;
       }
       while(true)
       {
              while(rd<wr)
              {      x=q[rd++];
                      for(y=0;y<n;y++)
                     {
                            if(cost[x][y]==lx[x]+ly[y] && T[y]==0)
                            {
                                   if(yx[y]==-1) break;
                                   T[y]=1;
                                   q[wr++]=yx[y];
                                   Adjust(yx[y],x);
                            }

                     }
                     if(y<n) break;
              }
              if(y<n) break;
              Update();
              wr=rd=0;
              for(y=0;y<n;y++) if(slack[y]==0 && !T[y])
              {
                     if(yx[y]==-1)
                     {
                            x=slackx[y];
                            break;
                     }
                     else
                     {
                            T[y]=1;
                            if(S[yx[y]]==0)
                            {
                                   q[wr++]=yx[y];
                                   Adjust(yx[y],slackx[y]);
                            }
                     }
              }
              if(y<n) break;
       }
       if(y<n)
       {
              max_match++;
              for(int cx=x,cy=y,ty; cx!=-2;cx=prev[cx],cy=ty)
              {
                     ty=xy[cx];
                     xy[cx]=cy;
                     yx[cy]=cx;
              }
              agument();
       }
}
int hungarian()
{
       int ret=0,x;
       max_match=0;
       memo(xy,-1);
       memo(yx,-1);
       ini();
       agument();

       for(x=0;x<n;x++) ret+=cost[x][xy[x]];
       return ret;

}
int main()
{  int cs,t,i,j;
   scanf("%d",&t);
   for(cs=1;cs<=t;cs++)
   {
          scanf("%d",&n);
          for(i=0;i<n;i++)
            for(j=0;j<n;j++) scanf("%d",&cost[i][j]);
            printf("Case %d: %d\n",cs,hungarian());
   }
   return 0;
}
