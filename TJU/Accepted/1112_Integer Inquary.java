
import java.util.Scanner;
import java.math.BigInteger;

public class Main 
{
	public static void main(String[] args)
    {
    	Scanner input = new Scanner(System.in);
    	
    	BigInteger a, b;
    	b = new BigInteger("0");
    	
    	while(input.hasNextBigInteger())
    	{
    		a = input.nextBigInteger();
    		if(a.compareTo(BigInteger.ZERO)==0)
    			break;
    			
    		b = b.add(a);
    		
    		
    	}
    	System.out.println(b);
        
    }
}
