#include<iostream>
using namespace std;
main()
{
    int i, j, k, n, flag, t;
    int a[10000];
    k=-1;
    for(i=0;i<=9999;i++)
    {
        t=i;
        flag = 1;
        while(t>0)
        {
            j=t%10;
            if(j==2||j==3||j==5||j==6||j==7||j==8)
            {
                flag=0;
                break;
            }
            t=t/10;
        }
        if(flag==1)
        {
            a[++k]=i;
            cout<<k<<": "<<a[k]<<endl;
        }
    }
}
