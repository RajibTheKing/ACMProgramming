#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    int T, kase=0;
    cin>>T;
    double t1, t2;
    long long x, b;

    while(T--)
    {
        cin>>x;
        b=2;
        while(1)
        {
            t1 = log(x)/log(b);
            t2 = floor(t1);
            if(t1-t2==0.0)
                break;
            b++;
            if(b>32)
            {
                t1=1.0;
                break;
            }
        }

        printf("Case %d: %0.0lf\n", ++kase, t1);
    }
}
