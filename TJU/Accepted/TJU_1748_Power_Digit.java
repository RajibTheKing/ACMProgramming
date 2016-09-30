package TJU_Problems;

import java.util.Scanner;
import java.math.BigInteger;

public class TJU_1748_Power_Digit
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        BigInteger n, m, ans;
        
        BigInteger TEN = new BigInteger("10");

        while(input.hasNext())
        {
            m = input.nextBigInteger();
            n = input.nextBigInteger();
            if(m.equals(BigInteger.ZERO)&&n.equals(BigInteger.ZERO)) break;

            ans = m.modPow(n, TEN);
            
            System.out.println(ans);

            
        }
    }

}
