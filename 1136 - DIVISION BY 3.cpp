
//BISMILLAHIRRAHMANIRRAHIM
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int l=1;l<=n;l++)
	{   int x,y,a,b;
	    cin>>x>>y;
	    if((x+1)%3==0)
	    {  x--;
	        a=x-((x/3)+1);
	    }

	    else
            a=x-((x/3)+1);
	    if(y%3!=0)
		    b=y-((y/3)+1);
	    else
		    b=y-(y/3);
	    //cout<<a<<"\t"<<b<<endl;
	    printf("Case %d: %d\n",l,b-a);
	}

    return 0;
}
