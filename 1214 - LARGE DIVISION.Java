
import java.util.Scanner;
import java.math.BigInteger;
public class Main
{
        public static void main( String args[])
        {   Scanner inp=new Scanner (System.in);
           int kase=1,n;
           BigInteger a,b,c;
           while(inp.hasNext())
           {
           n=inp.nextInt();
           for(kase=1;kase<=n;kase++)
           {
                 a=inp.nextBigInteger();
                 b=inp.nextBigInteger();
                 c=a.remainder(b);
                 if(c.compareTo(BigInteger.ZERO)!=0) System.out.println("Case "+(kase)+": not divisible");
                 else System.out.println("Case "+(kase)+": divisible");
           }
          }
        }
}
