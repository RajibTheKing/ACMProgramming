#include<iostream.h>
int main()
{
    int count;
    int n;

    while(1)
    {
        cin>>n;
        if(n==0)
            break;
        count=0;
        for(; ;)
        {
            if(n==1)
            {
                count++;
                break;
            }
           else if(n%2==0)
            {
                n=n/2;
                count++;
            }
            else if(n%2!=0)
            {
                n=3*n+1;
                count++;
            }

        }
        cout<<count<<endl;
    }
}
