
package UVA_Online_Judge;
import java.text.Format;
import java.util.Scanner;
public class UVA_353
{
    static String store[] = new String[5000];
    static int item;

    public static boolean isPalindrome(String a)
    {
        //System.out.println(a);
        
        for(int i=0;i<item;i++)
            if(a.compareTo(store[i])==0)
                return false;
        store[item++] = a;

        char p[] = new char[500];

        p = a.toCharArray();

        for(int i=0, j=a.length()-1;i<=j;i++, j--)
            if(p[i]!=p[j])
                return false;

        return true;
    }
    public static int compute(String a)
    {
        char p[] = new char[500];
        p = a.toCharArray();
        String temp;
        int kount=0, start, end;
        temp="";
        for(int i=1;i<=a.length();i++)
        {
            for(start=0, end=start+i;end<=a.length();start++, end++)
            {
                temp="";
                for(int j=start;j<end;j++)
                    temp+=p[j];
                if(isPalindrome(temp)) kount++;
            }
        }
        return kount;

    }

    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        String a;
        int ans;

        while(input.hasNext())
        {
            a = input.next();
            item=0;

            ans=compute(a);
            System.out.println("The string '"+a+"' contains "+ans+" palindromes.");
        }

    }

}
