#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    int row;
    int column;
    int form;
    char str[100000];
} data;

data convert(char str[]);
void transform(int n, char str[], int i);

char arr[] = {'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y'};

int main (void)
{
    char str[100000];
    int t, r, c, i;
    data inf;

    scanf ("%d", &t);
    while(t--)
    {
        scanf ("%s", str);
        inf = convert(str);

        if (inf.form == 1) printf ("R%dC%d\n", inf.row, inf.column);
        else
        {
            for (i=strlen(inf.str)-1; i>=0; i--) putchar(inf.str[i]);
            printf ("%d\n", inf.row);
        }
    }
    return 0;
}

data convert(char str[])
{
    int i, c=0, form=0;
    data inf;

    for (i=0; str[i]!='\0'; i++)
    {
        if (str[i]>='0' && str[i]<='9' && form==0) form = 1;
        if (str[i]=='C' && form==1)
        {
            form = 2;
            break;
        }
    }

    if (form==1)
    {
        for (i=0; str[i+1]>='A' && str[i+1]<='Z'; i++)
        {
            c += str[i]-'A'+1;
            c *= 26;
        }
        c += str[i]-'A'+1;
        inf.row = atoi(&str[i+1]);
        inf.column = c;
        inf.form = 1;
    }
    else
    {
        for (i=1; str[i]!='C'; i++)
            inf.str[i-1] = str[i];
        inf.str[i-1] = '\0';
        inf.row = atoi(inf.str);
        inf.form = 2;
        inf.column = atoi(&str[i+1]);
        transform(inf.column, inf.str, 0);
    }
    return inf;
}

void transform(int n, char str[], int i)
{
    int a;
    if (!n)
    {
        str[i] = '\0';
        return;
    }

    a = n%26;
    str[i] = arr[a];
    if (a==0) transform(n/26 - 1, str, i+1);
    else transform(n/26, str, i+1);

    return;
}
