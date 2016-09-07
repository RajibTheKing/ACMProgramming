#include<stdio.h>
#include<string.h>

char a[1010], b[1010];
int c[1010][1010];


int max(int p, int q)
{
    if(p>q) return p;
    else return q;
}
main()
{
    int i, j, k, l1, l2;
    while(scanf(" %[^\n] %[^\n]", a, b)==2)
    {
        memset(c, 0, sizeof(c));

        l1=strlen(a)+1;
        l2=strlen(b)+1;



        for(i=1;i<l1;i++)
        {
            for( j=1;j<l2;j++)
            {
                if(a[i-1]==b[j-1])
                {
                    c[i][j]=c[i-1][j-1]+1;
                }
                else
                {
                    c[i][j]=max(c[i-1][j], c[i][j-1]);
                }
            }
        }
        printf("%d\n", c[l1-1][l2-1]);
    }

}
