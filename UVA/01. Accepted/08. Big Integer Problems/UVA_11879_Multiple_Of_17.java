

package UVA_Online_Judge;

import java.util.Scanner;
import java.math.BigInteger;
public class UVA_11879_Multiple_Of_17
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        BigInteger temp, ans, check, num;
        num = new BigInteger("17");

        while(input.hasNext())
        {
            temp = input.nextBigInteger();
            if(temp.compareTo(BigInteger.ZERO)==0) break;
            check = temp.mod(num);
            if(check.compareTo(BigInteger.ZERO)==0)
                System.out.println(1);
            else
                System.out.println(0);
        }

    }

}
