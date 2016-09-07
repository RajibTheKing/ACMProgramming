#include<iostream.h>
#include<string.h>
int main()
{
    char b[20];
    char c;
    int i, j=-1, flag=0;
    while(scanf("%c", &c)==1)
    {
        if(c==' ')
        {
            for(i=j; i>=0; i--)
                printf("%c", b[i]);
            printf(" ");
            j=-1;
            continue;
        }
        if(c=='\n')
        {
            for(i=j; i>=0; i--)
                printf("%c", b[i]);
            printf("\n");
            j=-1;
            continue;
        }
        b[++j]=c;

    }

    return 0;
}
