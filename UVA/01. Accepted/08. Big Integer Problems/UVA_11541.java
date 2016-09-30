

package UVA_Online_Judge;
import java.util.Scanner;
public class UVA_11541
{
    public static String compute(String a)
    {
        String temp="", num="";
        char p[] = new char[500];

        p=a.toCharArray();
        for(int i=0;i<a.length();i++)
        {
           if(p[i]>='A'&&p[i]<='Z') continue;
           else
           {
               num="";
               int j;
               for(j=i;j<a.length();j++)
               {
                   if(p[j]>='A'&&p[j]<='Z') break;
                   else num+=p[j];
               }
               for(int k=0;k<Integer.parseInt(num);k++)
                   temp+=p[i-1];
               i=--j;
           }
        }

        return temp;
    }
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);

        int t, kase=0, rajib;
        String a, ans="";
        t = input.nextInt();
        a = input.nextLine();
        



        while(t>0)
        {
            a=input.nextLine();
            ans = compute(a);
           // System.out.println(a);
            ++kase;
            t--;
            System.out.println("Case "+kase+": "+ans);
        }

    }

}
