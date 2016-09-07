#include<iostream.h>
#include<string.h>
main()
{
    char a[30];
    while(1)
    {
        gets(a);
        int i, j, k;
        k=strlen(a);
        for(i=k-1; i>=0; i--)
            printf("%c", a[i]);
        printf("\n");
    }

}
