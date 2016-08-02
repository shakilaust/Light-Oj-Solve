
#include <stdio.h>
#include <algorithm>
using namespace std;
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
int cs;
void solve()
{
    int sum=0,neg=0,pos,in,n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&in);
        if(in<0) neg++;
        sum+=abs(in);
    }
    if(neg==n) printf("Case %d: inf\n",cs); // judi sob number negetive hoiya jay taile konodin o ber hoite parbo na
    else
    {   pos=n-neg;
    /*
      ekhane ektu math korle bepar ta bujha jay. say 3ta numberi positive  3,6,9 taile expected value ki hobe
      E=(3+6+9)/3 kintu jhamela hoilo kono number negaitive hoile , kono number neg hoile asole bepar ta ki hobe? say ekta number er
      expected value hoilo T(number) judi number ta negative hoy taile total expected value number tar sathe add hobe line
      3
      3 -6 -9 er junno
      T(-6)=6+E
      T(-9)=9+E
      emne ki hobar kotha silo E=(num1+num2+.....)/total number
      ekhaneo same kaj korbo
       E=(3+(6+E)+(9+E))/3
      =>E=3/3+6/3+E/3+9/3+E/3
      =>E=(3+6+9)/3+(2E)/3
      =>E-(2E)/3=(3+6+9)/3
      =>(3E-2E)/3=(3+6+9)/3
      =>E(3-2)/3=(3+6+9)/3
      =>E(total number-negative number)/total number=(sum of all numbers)/total number
      total number cancel kore dile
     => E(total number - negative number)=(sum)
     => E=(sum)/(total number-negative number)
      :::::::::::::::::eitai formula::::::::::::::::

    */
        printf("Case %d: %d/%d\n",cs,sum/gcd(sum,pos),pos/gcd(sum,pos));
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    for(cs=1;cs<=t;cs++) solve();
}
