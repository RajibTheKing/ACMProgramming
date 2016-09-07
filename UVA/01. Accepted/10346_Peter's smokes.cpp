#include<stdio.h>
main()
{
     long n,k, s1, s2, sum;
     while(scanf("%ld %ld",&n,&k)==2)
     {
         s1=n;
         sum=0;
         s2=0;
         while(s1>0)
         {
             sum=sum+s1;
             s1=s1+s2;
             s2=s1%k;
             s1=s1/k;
         }
         printf("%d\n", sum);

     }
}
