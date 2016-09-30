

package UVA_Online_Judge;
import java.math.BigInteger;
import java.util.Scanner;

public class UVA_10220_I_Love_Big_Numbers
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


    }

    public static void main(String args[])
    {
        Scanner input = new Scanner(System.in);

        Calculate();
        String s;
        char Num[] = new char[500000];
        
        int t, kount, n, sum;
        while(input.hasNext())
        {
            n=input.nextInt();
            
            s=dp[n].toString();
            Num=s.toCharArray();
            sum=0;
            for(int i=0;i<Num.length;i++)
            {
                int temp=Num[i]-'0';

                sum+=temp;
            }
            System.out.println(sum);

        }
    }
}
