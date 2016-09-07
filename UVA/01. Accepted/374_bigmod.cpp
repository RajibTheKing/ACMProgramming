#include<iostream.h>
int binary[60];
int function(int x);
int main()
{
    int i, k, temp, result, base, power, modulo;
    while(scanf("%d %d %d", &base, &power, &modulo)==3)
    {
        result = 1;
        temp=base%modulo;
        k=function(power);
        for(i=0; i<k; i++)
        {
            if(binary[i]==1)
                result=(result*temp)%modulo;
            temp=(temp*temp)%modulo;
        }
        printf("%d\n", result);

    }

}
int function(int x)
{
    int i;
    for(i=0;x>0;i++)
    {
        binary[i]=x%2;
        x=x/2;
    }
    return i;
}
