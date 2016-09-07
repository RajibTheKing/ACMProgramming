#include<iostream.h>
struct tag
{
    int b;
    int g;
    int c;

};
int main()
{
    char p,q, r;
    tag bin1, bin2, bin3;
    int ans;
    int brown, green, clear;
    int flag1, flag2, flag3;
    while(1)
    {
        flag1=0;
        flag2=0;
        flag3=0;

        scanf("%d %d %d %d %d %d %d %d %d", &bin1.b, &bin1.g, &bin1.c,&bin2.b, &bin2.g, &bin2.c, &bin3.b, &bin3.g, &bin3.c);
       // printf("%d %d %d %d %d %d %d %d %d", bin1.b, bin1.g, bin1.c,bin2.b, bin2.g, bin2.c, bin3.b, bin3.g, bin3.c);
       brown=bin1.b;
       p="B";
       flag1=1;
       if(brown<bin2.b)
            {
                brown=bin2.b;
                q="B";
            }



    }

    return 0;
}
