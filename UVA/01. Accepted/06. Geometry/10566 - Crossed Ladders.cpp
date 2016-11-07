#include<bits/stdc++.h>
using namespace std;
#define EPS 0.00001

double Abs(double a, double b)
{
    if(a>b)
        return a-b;
    else return b-a;
}
int main()
{

    double X, Y, H, a, h1, h2, tempH, mid;
    while(cin>>X>>Y>>H)
    {

        double left = 0.0;
        double right = X>Y?Y:X;


        int knt = 0;

        while(true)
        {
            mid = (left+right)/2.0;

            h1 = sqrt(X*X-mid*mid);
            h2 = sqrt(Y*Y-mid*mid);
            tempH = h1*h2/(h1+h2);
            if(H<tempH)
            {
                left=mid;
            }
            else
            {
                right=mid;
            }

            knt++;
          //  cout<<"Now diff = "<<Abs(H,tempH)<<endl;
            if(Abs(H, tempH)<EPS)
            {
                break;
            }

            if(knt>1000) break;


        }

        //cout<<knt<<endl;

        printf("%0.3lf\n", mid);
    }
}
