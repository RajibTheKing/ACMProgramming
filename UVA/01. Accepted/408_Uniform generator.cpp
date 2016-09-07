#include<iostream.h>
main()
{
    int step, mod, flag, seed, temp1, temp2;
    while(scanf("%d %d", &step, &mod)==2)
    {
        temp1=step; temp2=mod;

        for(; ;)
        {
            flag=temp2%temp1;
            if(flag==0)
            {
                flag=temp1;
                break;
            }
            temp2=temp1;
            temp1=flag;

        }

        if(flag==1)
            printf("%10d%10d    Good Choice\n", step, mod);
        else
            printf("%10d%10d    Bad Choice\n", step, mod);

            printf("\n");
    }
}
