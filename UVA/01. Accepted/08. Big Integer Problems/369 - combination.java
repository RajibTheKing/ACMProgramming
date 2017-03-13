import java.util.Scanner;
import java.math.BigInteger;

public class Main 
{
    public static void main(String[] args) 
    {
   		Scanner input = new Scanner(System.in);
   		BigInteger nf, mf,n_mf, fact, one, ans;
   		one = new BigInteger("1");
   		int n, m, n_m;
   		while(input.hasNext())
   		{
   			n=input.nextInt();
   			m=input.nextInt();
   			if(n==0&&m==0) break;
   			
   			fact=new BigInteger("1");
   			nf=fact;
 
   			for(int i=1;i<=n;i++)
   			{
   				nf = nf.multiply(fact);
   				fact=fact.add(one);
   			}
   			
   			fact=new BigInteger("1");
   			mf=fact;
 
   			for(int i=1;i<=m;i++)
   			{
   				mf = mf.multiply(fact);
   				fact=fact.add(one);
   			}
   			n_m = n-m;
   			fact=new BigInteger("1");
   			n_mf=fact;
 
   			for(int i=1;i<=n_m;i++)
   			{
   				n_mf = n_mf.multiply(fact);
   				fact=fact.add(one);
   			}
   			
   			ans = nf.divide(mf);
   			ans = ans.divide(n_mf);
   			System.out.println(n + " things taken "+m+" at a time is "+ans+" exactly.");
   			
   		}
   		
    }
}
