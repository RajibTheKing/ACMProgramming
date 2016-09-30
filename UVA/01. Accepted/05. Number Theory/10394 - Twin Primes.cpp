#include<stdio.h>
#include<string.h>
#define s 18409999
long flag[s];
long twin[100001];
int main()
{

    long i, j=0, k, t1=0, t2, temp;
    for(i=2; i<=s; i++)
    {

       if(flag[i]==0)
        {

            t2=i;
            temp=t2-t1;
            if(temp==2)
            {

                twin[j++]=t1;

            }
            if(j==100001)
                goto end;
            for(k=i+i; k<=s; k=k+i)
            {
                flag[k]=1;
            }
            t1=t2;
        }
    }
end:
    while(scanf("%d", &j)==1)
        printf("(%d, %d)\n",twin[j], twin[j]+2);

    return 0;
}


