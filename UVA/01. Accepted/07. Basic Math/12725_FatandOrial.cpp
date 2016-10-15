#include<iostream>
using namespace std;

int main()
{
    double N, M, A, B;
    int Test;
    cin>>Test;
    int kase = 0;
    while(Test--)
    {
        cin>>N>>M>>A>>B;

        double total1 = N*A;
        double total2 = (A+B)*M;
        double diff = total2-total1;

        cout<<"Case #"<<(++kase)<<": ";
        if(diff<0)
        {
            cout<<"Impossible"<<endl;
        }
        else
        {
            double avg = diff/B;
            if(avg<0||avg>10)
                cout<<"Impossible"<<endl;
            else
                printf("%0.2lf\n", avg);
        }

    }
    return 0;
}
