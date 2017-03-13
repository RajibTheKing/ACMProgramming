#include<iostream>
#include<string.h>
using namespace std;

int main()
{
    int bars[2000];
    int n, temp;
    while(cin>>n)
    {
        memset(bars, 0, sizeof(bars));
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            bars[temp]++;

        }
        int maxx=0, kount=0;
        for(int i=0;i<1001;i++)
        {
            if(bars[i]>maxx) maxx = bars[i];
            if(bars[i])
                kount++;
        }
        cout<<maxx<<" "<<kount<<endl;

    }
}
