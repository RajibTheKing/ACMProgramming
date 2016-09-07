#include<iostream.h>
#include<math.h>
int main()
{
    float a , b, c;
    int count=0;
    while(1){
    cin>>a;
    cin>>b;
    cin>>c;

    if(a==0&&b==0&&c==0)
        goto end;

    if(c>0)
    {
        if(a>=c||b>=c)
        {
            count++;

            printf("Triangle #%d\nImpossible.", count);
            goto f;
        }
    }

    if(c<0)
    {
        count++;
        c=sqrt(a*a+b*b);
        printf("Triangle #%d\nc = %.3f",count,  c);
    }

    if(a<0&&c>0)
    {
        count++;
        a=sqrt(c*c-b*b);
        printf("Triangle #%d\na = %.3f", count, a);
    }
    if(b<0&&c>0)
    {
        count++;
        b=sqrt(c*c-a*a);
        printf("Triangle #%d\nb = %.3f",count, b);
    }
f:

    printf("\n\n");




    }
end:
    return 0;

}
