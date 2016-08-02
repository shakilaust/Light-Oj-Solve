
import java.math.BigInteger;
import java.util.Scanner;
//import static java.lang.System.*;
class Main{
public static void main(String args[])
{

	Scanner sc=new Scanner(System.in);

	int i=sc.nextInt();
	for(int j=1;j<=i;j++)
	{
		int t=sc.nextInt();
		BigInteger one=sc.nextBigInteger();
		BigInteger two=sc.nextBigInteger();
		BigInteger pre=(one.multiply(two)).divide(one.gcd(two));

		for(int u=3;u<=t;u++)
		{
			BigInteger n=sc.nextBigInteger();
			pre=(pre.multiply(n)).divide(pre.gcd(n));


		}

		System.out.println("Case "+j+": "+pre);System.gc();

	}
}

}
