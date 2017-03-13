

import java.util.Scanner;
import java.math.BigInteger;

public class Main 
{
    public static void main(String[] args) 
    {
 		Scanner input = new Scanner(System.in);
 		BigInteger  ans[] = new BigInteger[5010];
 		int i;
 		BigInteger a, b;
 		a = new BigInteger("0");
 		b = new BigInteger("1");
 		
 		ans[0]=new BigInteger("1");
 		
 		for(i=1;i<=5000;i++)
 		{
 			ans[i] = a.add(b);
 			a = b;
 			b = ans[i];
 			
 		}
 		
 		int n;
 		while(input.hasNext())
 		{
 			n = input.nextInt();
 			i = n-1;
 			if(n==0)
 				System.out.println("The Fibonacci number for "+n+" is 0");
 			else
 				System.out.println("The Fibonacci number for "+n+" is "+ans[i]);
 			
 		}
      
    }
}
