
#include <stdio.h>
#include <algorithm>
#define MAX 100005
using namespace std;
bool v[MAX+5]; // sob 1st e 0i thakbe tai memset korar dhorkar nai
double E[MAX+5];
int cs,n;
double dfs(int num)
{
    if(num==1) return 0;
    if(v[num]) return E[num];
    v[num]=1;
    E[num]=0;
    int div=0,i;
    for(i=1;i*i<=num;i++)
    {
        if(num%i==0)
        {
            E[num]+=dfs(num/i); // ekhane mainly expected value gulo add korchi
            div++; // ami divisor er expected value gulo add korchi + eder songkao count kore rakhchi mane move oi divisor e jaowar
            if(i*i!=num) // 9 er junno hole 3*3 kintu same jinish, emon jinish gulo bandh deowar junno
            {
                div++;
                E[num]+=dfs(i);

            }
        }
    }
    E[num]+=div; // expected move e add dilam
    E[num]/=(div-1); // 1 minus korchi sob divior eri 1 ache , oitate kisui hobe na tai
    return E[num];
}
void solve()
{
    scanf("%d",&n);
    printf("Case %d: %lf\n",cs,dfs(n));
}
int main()
{
    int t;
    scanf("%d",&t);
    for(cs=1;cs<=t;cs++) solve();
}
