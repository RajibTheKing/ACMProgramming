

package UVA_Online_Judge;
import java.math.BigInteger;
import java.util.Scanner;

public class UVA_10183_How_Many_Fibs
{
    static BigInteger dp[] = new BigInteger[500];
    public static void Calculate()
    {
        dp[0] = new BigInteger("1");
        dp[1] = new BigInteger("2");
        int i;
        for(i=2;i<500;i++)
        {
            dp[i]=dp[i-1].add(dp[i-2]);
        }
        
    }

    public static void main(String args[])
    {
        Scanner input = new Scanner(System.in);
        
        Calculate();

        int t, kount;
        BigInteger a, b;

        //System.out.println(dp[480]);
        
        while(input.hasNext())
        {
            a=input.nextBigInteger();
            b=input.nextBigInteger();
            if(a.compareTo(BigInteger.ZERO)==0&&b.compareTo(BigInteger.ZERO)==0) break;
            if(a.compareTo(BigInteger.ZERO)==0)
                a=BigInteger.ONE;
            kount=0;
            for(int i=0;i<500;i++)
            {
                if(dp[i].compareTo(a)>=0&&dp[i].compareTo(b)<=0)
                    kount++;
                if(dp[i].compareTo(b)>0) break;
            }
            System.out.println(kount);
        }
    }


}
