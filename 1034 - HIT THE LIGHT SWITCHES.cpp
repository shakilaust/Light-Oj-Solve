
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int node ,e;
vector< int >edges[10002],Topo;
bool V[10002];
void dfs1( int u){
    V[u] = true ;
    for(int i = 0 ; i < edges[u].size(); i++ ){
        if( !V[ edges[u][i] ]){
            dfs1(edges[u][i]);
        }
    }
    Topo.push_back(u);
}
void dfs2( int u){
    V[u] = true ;
    for(int i = 0 ; i < edges[u].size(); i++ ){
        if( !V[ edges[u][i] ]){
            dfs2(edges[u][i]);
        }
    }
}
int main()
{
    int t,cs=1;
    cin >> t ;
    while(t--)
    {
        cin >> node >> e;
        for( int i = 0 ; i <= node ; i++ ) edges[i].clear();
        Topo.clear();
        while(e--){
            int u,v;
            cin >> u >> v ;
            edges[u].push_back(v);
        }
        memset(V,false,sizeof V);
        int cnt = 0;
        for( int i = 1 ; i <= node ; i++ ) if(!V[i]) dfs1(i);
        memset(V,false,sizeof V);
        reverse(Topo.begin(),Topo.end());
        for( int i = 0 ; i < Topo.size() ; i++ )
            if(!V[Topo[i]]) {
                dfs2(Topo[i]) ;
                cnt++;
                //cout << Topo[i]<<"  ";
            }
       // puts("");
        printf("Case %d: %d\n",cs++,cnt);
    }
    return 0;
}
