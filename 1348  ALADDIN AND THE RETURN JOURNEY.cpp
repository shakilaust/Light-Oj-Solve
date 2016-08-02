
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
#include <vector>
using namespace std;


//Fast Reader
template<class T>inline bool read(T &x){int c=getchar();int sgn=1;while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}for(x=0;~c&&'0'<=c&&c<='9';c=getchar())x=x*10+c-'0'; x*=sgn; return ~c;}

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

/* **************************************  My code start here ****************************************** */
const int MX =  30000 + 20 ;
const int LN = 17 ;
int tree[MX] , LA[MX][20] , Pos[MX] , SubTree[MX] , Start[MX] , ChainNo[MX] , Level[MX] , parnt[MX][20] , inp[MX];
int MaxV , Idx , ChainId , n , idx ;
vector < int > Adj[MX] ;

void Update(int idx, int val)
{
    while( idx <= MaxV )
    {
        tree[idx] += val ;
        idx += ( idx & -idx);
    }
}
int SUM(int idx)
{
    int ans = 0 ;
    while(idx)
    {
        ans += tree[idx];
        idx -= (idx & -idx);
    }
    return ans ;
}

void dfs(int to , int from , int lvl )
{
    Level[to] = lvl ;
    parnt[to][0] = from ;
    int sz = Adj[to].size();
    int i ;
    SubTree[to] = 1 ;
    for ( i = 0 ; i < sz ; i++ )
    {
        int v = Adj[to][i];
        if( v == from ) continue ;
     //   dist[v] = dist[to] + Adj[to][i].second;
        dfs(v,to,lvl+1);
        SubTree[to] += SubTree[v];

    }
}

void HLD(int u, int p )
{
    if (Start[ChainId] == -1)
        Start[ChainId] = u;

    ChainNo[ u ]   = ChainId;
    Pos[ u ]   = ++idx;

    Update( idx,inp[ u ] );

    int SpecialChild = -1, mx = -1;

    for (int i=0;i<Adj[u].size();i++){
        int v = Adj[u][i];

        if (v != p && SubTree[v] > mx){
            mx = SubTree[v];
            SpecialChild = i;
        }
    }

    if (SpecialChild != -1)     HLD( Adj[u][SpecialChild],u );

    for (int i=0;i<Adj[u].size();i++){
        if (i != SpecialChild){
            int v = Adj[u][i];

            if (v != p){
                ChainId++;
                HLD( v,u );
            }
        }
    }

}
void PreProcess(int n)
{
    int i , j ;
    for ( i = 0 ; i < n ; i++ )
    {
        for ( j = 0 ; ( 1 << j ) < n ; j++ ) parnt[i][j] = -1;
    }
    dfs(0,-1,0);
    for ( j = 1 ; (1 << j ) < n ; j++ )
    {
        for ( i = 0 ; i < n ; i++ )
        {
            if(parnt[i][j-1] != -1 )
            parnt[i][j] = parnt[parnt[i][j-1]][j-1];
        }
    }
}

int LCA(int a , int b)
{
    if( Level[a] < Level[b] ) swap(a,b) ; // a should have higher rank
    int lg , i;
    for ( lg = 1 ; ( 1 << lg ) <= Level[a] ; lg++ ) ;
    lg--;
    for ( i = lg ; i >= 0 ; i-- )
    {
        if( Level[a] - ( 1 << i ) >= Level[b] )
        {
            a = parnt[a][i];
        }
    }
    if( a == b ) return a ;
    for ( i = lg ; i >= 0 ; i-- )
    {
        if ( parnt[a][i] !=-1 && parnt[a][i] != parnt[b][i])
        {
            a = parnt[a][i] ;
            b = parnt[b][i] ;
        }
    }
    return parnt[a][0] ;
}

void ini()
{
    int i ;
    for ( i = 0 ; i <= n+1 ; i++ )
    {
        Adj[i].clear();
        //parnt[i] = -1 ;
        Start[i] = -1 ;
        ChainNo[i] = -1 ;
        tree[i] = 0 ;
    }
}
int tree_upto(int u , int v )
{
     int ans = 0;
    int uChain,vChain, tmp,st;

    while (1){
        uChain = ChainNo[ u ], vChain = ChainNo[ v ];
        //printf(" uchain :: %d vchain :: %d st :: %d \n",uChain,vChain , st);
        st = Start[ uChain ];

        if (uChain == vChain){
            ans += SUM( Pos[u] ) - SUM( Pos[v] - 1 );
            return ans;
        }

        ans += SUM( Pos[u] ) - SUM( Pos[st]-1 );

        u = parnt[st][0];
       //  printf(" st :: %d u :: %d \n",st , u );
    }
    return ans ;
}
int Solve(int u , int v )
{
    int _lc = LCA(u,v);
   // printf(" lc :: %d inp[lca] :: %d\n",_lc,inp[_lc]);
    int a = tree_upto(u,_lc);
    int b = tree_upto(v,_lc);
   // printf(" a :: %d b :: %d \n",a,b);
    return a + b - inp[_lc];
}
int main()
{
    // ios_base::sync_with_stdio(0); cin.tie(0);
    int cs , t , i;
    read(t);
    for ( cs = 1 ; cs <= t ; cs++ )
    {
        read(n);
        MaxV = n ;
        ini();
        for ( i = 0 ; i < n ; i++ )
        {
            read(inp[i]);
        }
        for ( i = 0 ; i < n-1 ; i++ )
        {
            int x , y ;
            read(x) , read(y) ;
            Adj[x].push_back(y);
            Adj[y].push_back(x);
        }
        PreProcess(n);
       // printf("LCA complete");
        idx = 0 ;
        ChainId = 1 ;
        HLD(0,-1);
        int q ;
        printf("Case %d:\n",cs);
        read(q);
        while(q--)
        {
            int type , x , y ;
            read(type) , read(x) , read(y);
            if( type )
            {
                Update(Pos[x] , -inp[x] );
                inp[x] = y ;
                Update(Pos[x] , inp[x] );
            }
            else
            {
                printf("%d\n",Solve(x,y));
            }

        }
    }


    return 0;
}
