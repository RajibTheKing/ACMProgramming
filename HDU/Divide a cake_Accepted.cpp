#include<iostream>
#include<math.h>

using namespace std;
main()
{
    double R, r1, r2;
    while(1)
    {

        cin>>R;
        if(R==0)
            break;
        r2=R*R/3;

        r1=2*r2;
        r1=sqrt(r1);
        r2=sqrt(r2);

        printf("%.3lf %.3lf\n", r2, r1);



    }

}
