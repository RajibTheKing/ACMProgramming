#include<iostream.h>
main()
{
    int a, b;
    a=0;

    int i=16;
    while(1)
    {

        i=16;
        while(1)
        {
            b=a&(1<<i);

            b=b>>i;

            cout<<b;
            i--;
            if(i<0)
                break;
        }
        cout<<endl;
        a++;
        if(a>50)
            break;
    }



}
