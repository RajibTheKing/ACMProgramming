
import java.util.Scanner;

public class Main
{
	public static void main(String[] args) 
	{
      	int t, ans;
      	boolean check = true, check2 = true;
      	
      	Scanner input = new Scanner(System.in);
      	int N;
      	
      	t = input.nextInt();
      	while(check==true)
      	{
      		
      		ans = 0;
      		check2  = true;
      		N = input.nextInt();
      		while(check2==true)
      		{
      			ans = ans + (N/5);
      			N=N/5;
      			if(N<=0) check2=false;
      			
      		}
      		
      		System.out.println(ans);
      		t--;
      		if(t==0)
      			check = false;
      	}
      	
    }
}

