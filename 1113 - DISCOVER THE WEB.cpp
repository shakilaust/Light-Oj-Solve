
#include <stdio.h>
#include <iostream>
#include <queue>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;
int main()
{  // freopen("input.txt","r",stdin);
    int kase=1,n;
    for(scanf("%d",&n);kase<=n;kase++)
    {   string hold,in="http://www.lightoj.com/";
        stack <string> Forward,Back;
       // Forward.push(in);
       printf("Case %d:\n",kase);
        Back.push(in);
        while(cin>>in)
        {    if(in=="QUIT") break;
             if(in=="VISIT")
             {
                 cin>>in;
                 cout<<in<<endl;;
                 Back.push(in);
                 while(!Forward.empty()) Forward.pop();
             }
             else if(in=="BACK" && Back.size()>1)
             {
                 hold=Back.top();
                 Back.pop();
                 cout<<Back.top()<<endl;
                 Forward.push(hold);
                 }


             else if(in=="FORWARD" && !Forward.empty())
             {
                 Back.push(Forward.top());

                 cout<<Forward.top()<<endl;
                      Forward.pop();

                              }
             else
             {
                 cout<<"Ignored\n";
             }
        }


    }

}
