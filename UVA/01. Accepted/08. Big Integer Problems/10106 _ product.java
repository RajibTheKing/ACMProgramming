
import java.math.BigInteger;
import java.util.Scanner;

public class Main 
{
    public static void main(String[] args) 
   	{
   		Scanner input  = new Scanner(System.in);
   		BigInteger a, b, ans;
   		
   		while(input.hasNext())
   		{
   			a = input.nextBigInteger();
   			b = input.nextBigInteger();
   			
   			ans = a.multiply(b);
   			
   			System.out.println(ans);
   			
   		}
        
    }
}
