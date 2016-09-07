#include<stdio.h>
#include<string.h>


typedef struct node
{
    char a[100];
    int b;
};

main()
{
    node DNA[100], temp, temp2;
    int i, j, k, t, m, n, kase=0;
    char c;
    scanf("%d", &t);
    while(t--)
    {

        scanf("%d%d", &n, &m);
        scanf("%c", &c);
        if(kase>0)
            printf("\n");
        kase++;

        for(i=0;i<m;i++)
            scanf(" %s", &DNA[i].a);


        for(i=0;i<m;i++)
        {
            DNA[i].b=0;
            for(j=0;j<n-1;j++)
            {
                c=DNA[i].a[j];
                for(k=j+1;k<n;k++)
                {
                    if(DNA[i].a[k]<c)
                        DNA[i].b++;

                }
            }
        }


        for(j=1;j<m;j++)
        {
            temp=DNA[j];
            i=j-1;
            while(i>-1&&DNA[i].b>temp.b)
            {
                DNA[i+1]=DNA[i];
                i--;
            }
            DNA[i+1]=temp;
        }


        for(i=0;i<m;i++)
        {
            printf("%s\n", DNA[i].a);
        }
    }
}
