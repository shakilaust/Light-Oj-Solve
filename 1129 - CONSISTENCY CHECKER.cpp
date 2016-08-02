
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
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>
#include <set>
#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <list>
#include <map>
#include <queue>
#include <sstream>
#include <utility>
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
#define INF 1LL<<31-1
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define memo(a,b) memset((a),(b),sizeof(a))
#define G() getchar()


using namespace std;


template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
string sanim[10005];
bool flag;
struct node
{       int val;
        node *next[15];
        node(){
                val=0;
                int i;
                for(i=0;i<15;i++)
                        next[i]=NULL;
        }
};

node *root=new node();
void insert(string str){
        node *curr=root;
        int i,sz=SZ(str);
        for(i=0;i<sz;i++){
                if(curr->next[str[i]-'0']==NULL){
                        curr->next[str[i]-'0']=new node();
                        flag=false;
                }
                curr=curr->next[str[i]-'0'];
        }
        curr->val++;
}
void traverse(node *p){

        int i;
        for(i=0;i<15;i++){
                if(p->next[i]!=NULL){
                        traverse(p->next[i]);
                    delete p->next[i];
                    p->next[i] = NULL;
                }
        }
}
bool cmp(string a,string b)
{
        return a.size()>b.size();
}

int main()
{

    //freopen("in.txt", "r", stdin);
    int cs,T;
    sc(T);
    FOR(cs,1,T)
    {
           int n,i;
           sc(n);
           rep(i,n) cin>>sanim[i];
           sort(sanim,sanim+n,cmp);
           //rep(i,n) cout<<sanim[i]<<endl;
           rep(i,n)
           {
                   flag=true;
                   insert(sanim[i]);
                   if(flag) { break; }

           }
            traverse(root);
            printf("Case %d: %s\n",cs,!flag?"YES":"NO");

    }



}
