#include<iostream.h>
#include<math.h>
int  binary_decimal[100], binary_hexadecimal[100];

int convert1(int m)
{
    int j=-1, i;
    for(;;)
    {
        i=m%2;
        binary_decimal[++j]=i;
        m=m/2;
        if(m==0)
            return j;
    }
}

int convert2(int m)
{
    int a[100];
    int i, j, k;
    for(i=0; ;i++)
    {
        j=m%10;
        a[i]=j;
        m=m/10;

        if(m==0)
            break;
    }


    k=0;
    for(j=0; j<=i; j++)
    {
        k=k+pow(16, j)*a[j];
    }

    j=-1, i;
    for(;;)
    {
        i=k%2;
        binary_hexadecimal[++j]=i;
        k=k/2;
        if(k==0)
            return j;
    }


}

main()
{
    char a[100];

    int t, m, i, b1, b2, x, y;
    cin>>t;
    while(t--)
    {
        memset(binary_decimal, -1, sizeof(binary_decimal));
        memset(binary_hexadecimal, -1, sizeof(binary_hexadecimal));
        cin>>m;
        b1= convert1(m);

        x=0;
        for(i=b1; i>=0; i--)
        {
            if(binary_decimal[i]==1)
                x++;
        }

        b2=convert2(m);

        y=0;
        for(i=b2; i>=0; i--)
        {
            if(binary_hexadecimal[i]==1)
                y++;
        }

        printf("%d %d\n", x, y);


    }

}
