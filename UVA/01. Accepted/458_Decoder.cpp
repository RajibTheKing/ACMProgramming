#include<iostream.h>
int main()
{
    char a;
    while(scanf("%c", &a)==1)
    {
        if(a!='\n')
            printf("%c", a-7);
        else
            printf("\n");

    }
    return 0;
}
