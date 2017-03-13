import java.math.BigInteger;
import java.util.Scanner;


public class Main 
{
    public static void main(String[] args) 
    {
    	Scanner input = new Scanner(System.in);
    	BigInteger x, y, a, b, c, i;
    	b = new BigInteger("1");
    	
        while(input.hasNextBigInteger())
        {
        	x = input.nextBigInteger();
        	y = input.nextBigInteger();
        	
        	
        	a = x.gcd(y);
        	
        	c = x.multiply(y);
        	
        	a = c.divide(a);
        	
        	c = a.divide(x);
        	
        	System.out.println(c);
        }
    }
}