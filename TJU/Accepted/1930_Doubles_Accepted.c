#include<stdio.h>
int main()
{
    while(1<2){
    int a[20];
    int i,j, temp, count=0, max=0, t;
    for(i=0; ; i++)
    {
        scanf("%d", &a[i]);


        if(a[i]==0)
            break;
        if(a[i]==-1)
            goto end;

    }
    for(i=0; ; i++)
    {
        temp=a[i];
        if(temp==0)
            break;
        for(j=0; ; j++)
        {
            t=a[j]*2;
            if(temp==t)
            {
                count++;
                break;
            }
            if(a[j]==0)
                break;
        }
    }
    printf("%d\n", count);


    }
end:
    return 0;
}


