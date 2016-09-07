#include<iostream.h>
#include<string.h>

char a[500];
main()
{
    char b[50];
    gets(b);

    int n;

    n=atoi(b);
    int i, j, k, score, flag;
    while(n--)
    {
        score=0; flag=0;
        memset(a, 0, sizeof(a));

        gets(a);
        k=strlen(a);

        for(i=0; i<k; i++)
        {
            if(a[i]=='O')
            {
                flag++;
                score=score+flag;
            }
            if(a[i]=='X')
                flag=0;
        }

        printf("%d\n", score);


    }

}
