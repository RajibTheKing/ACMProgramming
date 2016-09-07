#include<iostream.h>
#include<string.h>
char a[75];
char b[75];
void out(int k, int j)
{
        int i, l;
        for(i=0; i<k; i++)
                b[--j]=a[i];
        l=strlen(b);
        for(i=0; i<k; i++)
                printf("%c", b[i]);
        printf("\n");
        return;
}
int main()
{
        int n;
        scanf("%d\n", &n);
        while(n)
        {
                int i, j, k, l;

                gets(a);
                k=strlen(a);
                j=k;
                out(k, j);

                n--;
        }

        return 0;
}
