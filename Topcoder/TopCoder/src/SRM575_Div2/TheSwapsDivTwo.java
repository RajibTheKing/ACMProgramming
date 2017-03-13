package SRM575_Div2;

import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;

public class TheSwapsDivTwo 
{
    public int find(int[] sequence) 
    {
       int ans=0;
       boolean flag=true;
       for(int i=0;i<sequence.length;i++)
       {
           for(int j=i+1;j<sequence.length;j++)
           {
               if(sequence[i]!=sequence[j])
                   ans++;
               if(sequence[i]==sequence[j] && flag==true)
               {
                   flag=false;
                   ans++;
               }
               
                   
           }
       }
       return ans;
    }
}
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
