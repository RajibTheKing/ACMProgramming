#include<iostream.h>
char a[100000];
int main()
{
    int k, i;

    while(scanf("%s", a)!=EOF)
    {
        k=strlen(a);
        for(i=k; i>=0; i--)
            printf("%c", a[i]);
    }
    return 0;
}
