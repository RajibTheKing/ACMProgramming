
import java.util.Scanner;
import java.math.BigInteger;

public class Main 
{
   public static void main(String[] args) 
   {
   		Scanner input = new Scanner(System.in);
   		
   		BigInteger ans[] = new BigInteger[55];
   		BigInteger a, b;
   		
   		a = new BigInteger("0");
   		b = new BigInteger("1");
   		
   		int i;
   		
   		for(i=1;i<=50;i++)
   		{
   			ans[i]=a.add(b);
   		
   			a=b;
   			b=ans[i];
   		}
   		
   		
   		while(input.hasNextInt())
   		{
   			i = input.nextInt();
   			if(i==0)
   				break;
   			System.out.println(ans[i]);
   		}
   	
        
   }
}
