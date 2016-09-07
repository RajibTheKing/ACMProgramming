#include<stdio.h>
#include<math.h>
int coin[20],a[310];
int main()
{
    int n,m,i,j;
    for(i=0;i<20;i++){
        coin[i]=(i+1)*(i+1);

    }



    a[0]=1;

    for(i=0; i<=17; i++)
    {
        for(j=0; j<=300; j++)
        {
            a[j+coin[i]]+=a[j];
        }

    }

    while(scanf("%d",&n)==1&&n)
    {

        printf("%d\n",a[n]);
    }

}
