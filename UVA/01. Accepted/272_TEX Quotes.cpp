#include<iostream.h>
#include<string.h>
int main()
{
    char a;
    int flag=0;
    while(scanf("%c", &a)!=EOF)
    {
        if(a!='"')
            printf("%c", a);
        if(a=='"')
            {
                if(flag==0)
                    {
                        flag=1;
                        printf("``");
                    }
                else
                    {
                        flag=0;
                        printf("''");
                    }

            }
    }
    return 0;
}
