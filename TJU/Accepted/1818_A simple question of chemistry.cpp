#include<iostream.h>
main()
{
    double a=999, b;
    while(1)
    {
        cin>>b;
        if(b==999)
            break;
        if(a==999)
        {
            a=b;
            continue;
        }
        printf("%.2lf\n", b-a);
        a=b;
    }
    printf("End of Output\n");
}
