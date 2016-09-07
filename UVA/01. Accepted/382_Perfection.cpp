#include<stdio.h>
unsigned int  m,n;
int i=-1;
main()
{
  while(scanf("%u",&n)==1)
  {
    if(n==0)
    {
        printf("END OF OUTPUT\n");
        break;
    }
    if(i==-1)
    {
        printf("PERFECTION OUTPUT\n");
        i=0;
    }
    m=0;
    for(i=1;i<=n/2;i++)
    {
        if(n%i==0)
            m=m+i;
    }


	if(m==n)
		printf("%5u  PERFECT\n",n);

	if(m<n)
		printf("%5u  DEFICIENT\n",n);

	if(m>n)
		printf("%5u  ABUNDANT\n",n);
    }
}


