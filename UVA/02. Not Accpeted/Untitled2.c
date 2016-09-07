#include<stdio.h>
#include<string.h>
main()
{
    int k;

    char a[100];
    gets (a);
    k=strlen(a);
    printf("%d", k);
    a[k-1]=NULL;
    k=strlen(a);
    printf("\n%d", k);

}
