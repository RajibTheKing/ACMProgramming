import java.math.BigInteger;
import java.util.Scanner;


public class Main 
{
    public static void main(String[] args) 
    {
    	Scanner input = new Scanner(System.in);
    	BigInteger x, y;
    	int n;
    	n = input.nextInt();
    	while(n>0)
    	{
    		n--;
    		x=input.nextBigInteger();
    		y=input.nextBigInteger();
    		if(x.compareTo(y)==-1)
    			System.out.println("NO BRAINS");
    		else
    			System.out.println("MMM BRAINS");
    	}
        
    }
}
