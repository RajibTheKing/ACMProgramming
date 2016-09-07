#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>


char a[10000], b[100];

double power, voltage, current;


double make_value(int l)
{
    double value;
    char c, d[100];
    int i, j, k;
    memset(d, 0, sizeof(d));
    j=-1;
    for(i=0; ;i++)
    {
        if(b[i]=='W'||b[i]=='A'||b[i]=='V'||b[i]=='m'||b[i]=='M'||b[i]=='k')
            break;

        d[++j]=b[i];
    }



    value=atof(d);

    c=b[l-1];


    if(c=='m')
        value=value/1000;
    else if(c=='M')
        value=value*1000000;
    else if(c=='k')
        value=value*1000;
    else
        value=value;


    return value;
}

main()
{
    int i, j, k, t, l, f1, f2, f3,  kase=0;
    char c;

    scanf("%d", &t);
    scanf("%c", &c);
    while(t--)
    {
        memset(a, 0, sizeof(a));


        f1=0; f2=0; f3=0;
        gets(a);
        k=strlen(a);
        for(i=0;i<k;i++)
        {
            l=-1;
            if(a[i]=='=')
            {
                memset(b, 0, sizeof(b));
                for(j=i+1; ;j++)
                {
                    b[++l]=a[j];
                    if(b[l]=='W'||b[l]=='A'||b[l]=='V')
                        break;
                }

                if(a[i-1]=='P')
                {

                    power = make_value(l);
                    f1=1;
                }

                else if(a[i-1]=='U')
                {

                    voltage = make_value(l);
                    f2=1;
                }

                else if(a[i-1]=='I')
                {

                    current = make_value(l);
                    f3=1;
                }
            }
        }

        printf("Problem #%d\n", ++kase);
        if(f1==1&&f2==1)
        {
            printf("I=%.2lfA\n", power/voltage);
        }
        else if(f2==1&&f3==1)
        {
            printf("P=%.2lfW\n", voltage*current);
        }
        else if(f1==1&&f3==1)
        {
            printf("U=%.2lfV\n", power/current);
        }
        printf("\n");

    }
}

