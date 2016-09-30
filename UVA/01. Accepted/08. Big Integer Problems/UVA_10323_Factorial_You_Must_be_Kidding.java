

package UVA_Online_Judge;
import java.math.BigInteger;
import java.util.Scanner;

public class UVA_10323_Factorial_You_Must_be_Kidding
{
    static int MAX = 31;
    static BigInteger dp[] = new BigInteger[MAX];
    public static void Calculate()
    {
        dp[0] = new BigInteger("1");
        dp[1] = new BigInteger("1");
        int i;
        BigInteger M = new BigInteger("2");
        for(i=2;i<MAX;i++)
        {
            dp[i]=dp[i-1].multiply(M);
            M = M.add(BigInteger.ONE);
            //System.out.println(dp[i]);
        }
        //System.out.println(dp[i-1]);


    }

    public static void main(String args[])
    {
        Scanner input = new Scanner(System.in);

        Calculate();
        BigInteger UpperLimit = new BigInteger("6227020800");
        BigInteger LowerLimit = new BigInteger("10000");
        int n;
        while(input.hasNext())
        {
            n=input.nextInt();
            if(n<0)
            {
                n=Math.abs(n);
                if(n%2==0)
                    System.out.println("Underflow!");
                else System.out.println("Overflow!");
            }
            else if(n>29)
                System.out.println("Overflow!");
            else if(dp[n].compareTo(LowerLimit)<0)
                System.out.println("Underflow!");
            else if(dp[n].compareTo(UpperLimit)>0)
                System.out.println("Overflow!");
            else
                System.out.println(dp[n]);

           

        }
    }
}
