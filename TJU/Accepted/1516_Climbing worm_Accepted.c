#include<stdio.h>
int main()
{
    int n, u, d, i, count, temp;

    while(scanf("%d %d %d", &n,  &u, &d)==3)
    {
        temp=0;
        count=0;
        if(n==0)
            goto end;
        for(i=0; ; i++)
        {
            temp=temp+u;
            count++;
            if(temp>=n)
                break;

            temp=temp-d;
                count++;

        }

        printf("%d\n", count);

    }
end:
    return 0;

}


