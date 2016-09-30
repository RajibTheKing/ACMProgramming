

package UVA_Online_Judge;
import java.math.BigInteger;
import java.util.Scanner;

public class UVA_324_Factorial_Frequencies
{
    static int MAX = 380;
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
        int a[] = new int[200];
        int t, kount, n;
        while(input.hasNext())
        {
            n=input.nextInt();
            if(n==0) break;
            s=dp[n].toString();
            Num=s.toCharArray();
            for(int i=0;i<10;i++)
                a[i]=0;
            for(int i=0;i<Num.length;i++)
            {
                int temp=Num[i]-'0';
                
                //System.out.println(temp);
                a[temp]++;
            }
            System.out.println(n+"! --");
            System.out.printf("   (0)%5d    (1)%5d    (2)%5d    (3)%5d    (4)%5d\n",a[0],a[1], a[2], a[3], a[4]);
            System.out.printf("   (5)%5d    (6)%5d    (7)%5d    (8)%5d    (9)%5d\n",a[5],a[6], a[7], a[8], a[9]);
            
        }
    }
}
