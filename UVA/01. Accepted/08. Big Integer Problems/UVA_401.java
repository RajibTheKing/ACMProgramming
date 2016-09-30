
//UVA 401: Palindrome

package UVA_Online_Judge;
import java.util.Scanner;
public class UVA_401
{
    static char s[] = new char[500];

    public static boolean isMirrored(String a)
    {
        char p[] = new char[500];
        char t1, t2;
        p = a.toCharArray();
        for(int i=0, j=a.length()-1 ;i<=j;i++, j--)
        {
            t1=p[i];
            t2=p[j];
            if((p[i]=='O'||p[i]=='0')&&(p[j]=='O'||p[j]=='0'))
                continue;
            if(s[t1]==t2&&s[t2]==t1)
                continue;
            return false;
        }
        return true;
    }
    public static boolean isPalindrome(String a)
    {
        char p[] = new char[500];

        p = a.toCharArray();

        for(int i=0, j=a.length()-1;i<=j;i++, j--)
            if(p[i]!=p[j])
                return false;

        return true;
    }
    public static int compute(String a)
    {
        if(isPalindrome(a))
        {
            if(isMirrored(a))
                return 4;
            else return 2;


        }
        else
        {
            if(isMirrored(a))
                return 3;
            else return 1;
        }
         
    }
    
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        String a;
        int flag;

        s['A'] = 'A';
        s['B'] = '#';
        s['C'] = '#';
        s['D'] = '#';
        s['E'] = '3';
        s['F'] = '#';
        s['G'] = '#';
        s['H'] = 'H';
        s['I'] = 'I';
        s['J'] = 'L';
        s['K'] = '#';
        s['L'] = 'J';
        s['M'] = 'M';
        s['N'] = '#';
        s['O'] = 'O';
        s['P'] = '#';
        s['Q'] = '#';
        s['R'] = '#';
        s['S'] = '2';
        s['T'] = 'T';
        s['U'] = 'U';
        s['V'] = 'V';
        s['W'] = 'W';
        s['X'] = 'X';
        s['Y'] = 'Y';
        s['Z'] = '5';
        s['0'] = '0';
        s['1'] = '1';
        s['2'] = 'S';
        s['3'] = 'E';
        s['4'] = '#';
        s['5'] = 'Z';
        s['6'] = '#';
        s['7'] = '#';
        s['8'] = '8';
        s['9'] = '9';
      
        while(input.hasNext())
        {
            a = input.next();
            flag=compute(a);

            if(flag==1)         System.out.println(a+" -- is not a palindrome.");
            else if(flag==2)    System.out.println(a+" -- is a regular palindrome.");
            else if(flag==3)    System.out.println(a+" -- is a mirrored string.");
            else                System.out.println(a+" -- is a mirrored palindrome.");

            System.out.println("");
        }

    }

}
