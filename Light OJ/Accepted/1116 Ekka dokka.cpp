#include<iostream>
#include<math.h>
using namespace std;
main()
{
    long long T;
    long long i, j, w, t1, t2, kase=0;
    cin>>T;
    while(T--)
    {
        cin>>w;
        j=w;
        t1=1;
        while(w)
        {
            if(w%2==0)
            {
                t1*=2;
                t2=j/t1;
                if(t2%2==1)
                    break;
                w/=2;
            }

            else break;
        }
        if(w==1||t2==1||t1==1)
        {
            cout<<"Case "<<++kase<<": Impossible"<<endl;
        }
        else
        {
            cout<<"Case "<<++kase<<": "<<t2<<" "<<t1<<endl;
        }
    }
}
