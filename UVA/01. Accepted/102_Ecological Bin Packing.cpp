#include<stdio.h>

typedef struct node
{
    int brown;
    int green;
    int clear;
};

main()
{
    node bin1, bin2, bin3;
    char p, q, r;
    int ans, temp;

    while(scanf("%d %d %d %d %d %d %d %d %d", &bin1.brown, &bin1.green, &bin1.clear,&bin2.brown, &bin2.green, &bin2.clear,&bin3.brown, &bin3.green, &bin3.clear)==9)
    {
        ans=2147483647;

        temp=bin2.brown+bin3.brown+bin1.clear+bin3.clear+bin1.green+bin2.green;
        if(temp<ans)
        {
            p='B'; q='C'; r='G';
            ans=temp;
        }

        temp=bin2.brown+bin3.brown+bin1.green+bin3.green+bin1.clear+bin2.clear;
        if(temp<ans)
        {
            p='B'; q='G'; r='C';
            ans=temp;
        }

        temp =bin2.clear+bin3.clear+bin1.brown+bin3.brown+bin1.green+bin2.green;
        if(temp<ans)
        {
            p='C'; q='B'; r='G';
            ans=temp;
        }

        temp =bin2.clear+bin3.clear+bin1.green+bin3.green+bin1.brown+bin2.brown;
        if(temp<ans)
        {
            p='C'; q='G'; r='B';
            ans=temp;
        }

        temp =bin2.green+bin3.green+bin1.brown+bin3.brown+bin1.clear+bin2.clear;
        if(temp<ans)
        {
            p='G'; q='B'; r='C';
            ans=temp;
        }

        temp =bin2.green+bin3.green+bin1.clear+bin3.clear+bin1.brown+bin2.brown;
        if(temp<ans)
        {
            p='G'; q='C'; r='B';
            ans=temp;
        }

        printf("%c%c%c %d\n",p, q, r, ans);

    }

}
