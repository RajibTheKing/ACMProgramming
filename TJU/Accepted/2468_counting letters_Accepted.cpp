#include<iostream.h>
#include<string.h>
char a[105];
int b[26];
void out(int k)
{
        int i, l, max=0;
        for(i=0; i<k; i++)
        {
                l=a[i]-97;
                b[l]++;
        }
        for(i=0; i<26; i++)
                if(b[i]>max)
                        max=b[i];
        for(i=0; i<26; i++)
        {
                if(b[i]==max)
                        printf("%c", i+97);
        }
        printf("\n");

        return;
}
int main()
{
        int n;
        cin>>n;
        while(n)
        {
                int k;
                scanf("%s", a);
                k=strlen(a);
                memset(b, 0, 26*sizeof(int));
                out(k);
                n--;
        }
        return 0;
}
