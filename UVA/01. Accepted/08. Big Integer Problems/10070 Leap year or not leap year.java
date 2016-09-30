import java.math.BigInteger;
import java.util.Scanner;

public class Main 
{
    final static BigInteger FOUR=BigInteger.valueOf(4);
    final static BigInteger HUNDRED=BigInteger.valueOf(100);
    final static BigInteger FOUR_HUNDRED=BigInteger.valueOf(400);
    final static BigInteger FIFTEEN=BigInteger.valueOf(15);
    final static BigInteger FIFTYFIVE=BigInteger.valueOf(55);
    
    public static boolean l(BigInteger n) 
    {
    	return ( (n.mod(FOUR).equals(BigInteger.ZERO) && !n.mod(HUNDRED).equals(BigInteger.ZERO)) || (!(n.mod(FOUR).equals(BigInteger.ZERO) && !n.mod(HUNDRED).equals(BigInteger.ZERO))&&(n.mod(FOUR_HUNDRED).equals(BigInteger.ZERO))));    
   	}
    public static boolean h(BigInteger n) 
    {
    	return n.mod(FIFTEEN).equals(BigInteger.ZERO);
    }
    public static boolean b(BigInteger n) 
    {
     	return l(n) && (n.mod(FIFTYFIVE).equals(BigInteger.ZERO));
    }
    
    public static void main(String[] args) 
    {
    	Scanner in=new Scanner(System.in);
    	BigInteger n;
    	
    	for(boolean f=true;in.hasNextBigInteger();f=false) 
    	{
    		n=in.nextBigInteger();
    		if(!f) 
    			System.out.println();
    			
    		boolean o=true;
    		if(l(n)) 
    		{
    			 o=false;
    			 System.out.println("This is leap year.");
    		}
    		
    		if(h(n)) 
    		{
    			 o=false;
    			 System.out.println("This is huluculu festival year.");
    		}
    		
    		if(b(n)) 
    		{
    			o=false;
    			System.out.println("This is bulukulu festival year.");
    		}
    		
    		if(o) System.out.println("This is an ordinary year.");
    	}
    }
}