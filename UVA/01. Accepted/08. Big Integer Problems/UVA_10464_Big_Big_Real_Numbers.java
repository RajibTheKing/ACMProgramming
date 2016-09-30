package UVA_Online_Judge;
import java.math.BigDecimal;
import java.util.Scanner;

public class UVA_10464_Big_Big_Real_Numbers
{
    public static void main(String args[])
    {
        Scanner input= new Scanner(System.in);
        BigDecimal a,b, sum;
        String s;
        String s2;
        int n;
        n=input.nextInt();
        for(int i=0;i<n;i++)
        {
            a=input.nextBigDecimal();
            b=input.nextBigDecimal();
            sum=a.add(b);
            s=sum.toString();
            int kount=s.length();
            for(int j=s.length()-1;j>=0;j--)
            {
                if(s.charAt(j-1)=='.')
                    break;
                if(s.charAt(j)!='0')
                    break;
                kount--;
                
            }
            for(int j=0;j<kount;j++)
                System.out.print(s.charAt(j));
            System.out.println("");
            
            //System.out.println(sum);
            
        }
      

    }

}
