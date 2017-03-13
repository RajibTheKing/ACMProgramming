#include<iostream>
#include<math.h>
using namespace std;
double ans[1000010];

void calculate()
{
    ans[0]= 0;
    ans[1]=log(1);

    for(int i=2;i<=1000000;i++)
        ans[i]=ans[i-1]+log(i);
    //for(int i=1;i<10;i++)
        //cout<<ans[i]<<endl;
}

int main()
{
    calculate();
    //cout<<"complete"<<endl;

    int T, kase = 0;
    int n, b;
    double temp;
    cin>>T;
    while(T--)
    {
        cin>>n>>b;
        temp = ans[n];
        temp = temp/log(b);
        temp+=1.0;
        temp=floor(temp);
        printf("Case %d: %0.lf\n", ++kase, temp);
    }
}
