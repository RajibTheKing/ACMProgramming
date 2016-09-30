package UVA_Online_Judge;

//11734	Big Number of Teams will Solve This

import java.util.Scanner;

public class UVA_11734
{
    public static int check(String a, String b)
    {
        int l1, l2;
        l1=a.length();
        l2=b.length();

        char p[] = new char[500];
        char q[] = new char[500];
        p=a.toCharArray();
        q=b.toCharArray();

        if(a.compareTo(b)==0)
           return 1;
        a="";
        b="";
        for(int i=0;i<l1;i++)
        {
            if(p[i]==' ')
                continue;
            else
                a+=p[i];
        }

        for(int i=0;i<l2;i++)
        {
            if(q[i]==' ')
                continue;
            else
                b+=q[i];
        }
        if(a.compareTo(b)!=0)
            return 2;
        else
            return 3;

    }
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);

        int t, kase=0;
        String a, b;
        int flag=0;
        

        t = input.nextInt();
        a=input.nextLine();


        while(t>0)
        {
            a=input.nextLine();
            b=input.nextLine();
            flag = check(a, b);
            ++kase;
            t--;


            if(flag==1)
                System.out.println("Case "+kase+": Yes");
            else if(flag==2)
                System.out.println("Case "+kase+": Wrong Answer");
            else
                System.out.println("Case "+kase+": Output Format Error");
            
            
        }

    }

}
