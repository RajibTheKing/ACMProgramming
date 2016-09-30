

package UVA_Online_Judge;
import java.math.BigInteger;
import java.util.Scanner;

public class UVA_10579_Fibonacci_Numbers
{
    static int MAX = 5000;
    static BigInteger dp[] = new BigInteger[MAX];
    public static void Calculate()
    {
        dp[1] = new BigInteger("1");
        dp[2] = new BigInteger("1");
        int i;
        for(i=3;i<MAX;i++)
        {
            dp[i]=dp[i-1].add(dp[i-2]);
        }
        
        //System.out.println(dp[i-1]);
        //String s;
        //s=dp[i-1].toString();
        //System.out.println(s.length());

    }

    public static void main(String args[])
    {
        Scanner input = new Scanner(System.in);

        Calculate();

        int t, kount, n;
        while(input.hasNext())
        {
            n=input.nextInt();
            
            System.out.println(dp[n]);
        }
    }
}
