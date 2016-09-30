

package UVA_Online_Judge;


import java.util.Scanner;
import java.math.BigInteger;

public class UVA_10523_Very_Easy
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        BigInteger A, temp, t, ans;
        int N;
        while(input.hasNext())
        {
            N = input.nextInt();
            A = input.nextBigInteger();
            
            ans = new BigInteger("0");
            t = new BigInteger("0");

            for(int i=1;i<=N;i++)
            {
                t = t.add(BigInteger.ONE);
                temp = A.pow(i);
                temp = temp.multiply(t);
                ans = ans.add(temp);
                //System.out.println(temp + " " + t + " " + ans);
                
            }

            System.out.println(ans);
        }

    }

}
