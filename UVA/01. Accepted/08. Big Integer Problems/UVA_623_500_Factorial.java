

package UVA_Online_Judge;
import java.math.BigInteger;
import java.util.Scanner;

public class UVA_623_500_Factorial
{
    static int MAX = 1001;
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
        int n;
        while(input.hasNext())
        {
            n=input.nextInt();
            
            System.out.println(n+"!");
            System.out.println(dp[n]);

        }
    }
}
