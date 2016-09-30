

package UVA_Online_Judge;
import java.math.BigInteger;
import java.util.Scanner;

public class UVA_713_Adding_Reversed_Numbers
{
    public static void main(String args[])
    {
        Scanner input = new Scanner(System.in);

        //String Str="rajib";
       // String R = new StringBuffer(Str).reverse().toString();
       // System.out.println(R);

        int t=0;
        t=input.nextInt();
        String s1, s2, s;
        BigInteger a, b, sum, ans;

        for(int i=0;i<t;i++)
        {
            s1=input.next();
            s2=input.next();
            String R1 = new StringBuffer(s1).reverse().toString();
            String R2 = new StringBuffer(s2).reverse().toString();

            a = new BigInteger(R1);
            b = new BigInteger(R2);
            sum = a.add(b);
            s=sum.toString();
            String R = new StringBuffer(s).reverse().toString();
            ans = new BigInteger(R);
            System.out.println(ans);
        }
    }


}
