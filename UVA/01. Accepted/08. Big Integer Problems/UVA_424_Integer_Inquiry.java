

package UVA_Online_Judge;

import java.util.Scanner;
import java.math.BigInteger;
public class UVA_424_Integer_Inquiry
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        BigInteger temp, ans;
        ans = new BigInteger("0");
        
        while(input.hasNext())
        {
            temp = input.nextBigInteger();
            if(temp.compareTo(BigInteger.ZERO)==0) break;
            ans = ans.add(temp);
        }
        System.out.println(ans);
    }

}
