#include<stdio.h>
#include<math.h>
int main()
{
    int i, t, a, b;
    scanf("%d ", &t);


    for(i=0; i<t; i++)
    {
        scanf("%d", &a);
        scanf("%d", &b);
        if(a<b)
        printf("<\n");
        else if(a>b)
        printf(">\n");
        else
        printf("=\n");

    }

    return 0;
}
