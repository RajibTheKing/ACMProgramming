#include<stdio.h>
#include<iostream.h>
long long a[200005];
int main()
{
    long long i, j,temp1, temp, temp2, k;
    i=0;
    temp1=1;
    temp=1;
    temp2=1;
    for(; ;)
    {
        for(j=0; j<temp1; j++)
        {
            for(k=0; k<temp2; k++)
            {
                a[++i]=temp;
                cout<<i<<"."<<a[i]<<endl;
            }
            temp++;
        }
        temp2++;
        if(temp2%2==0)
        temp1++;

        if(i>10000)
            break;
    }


//    for(j=0; j<i; j++)
//        cout<<j<<"."<<a[i]<<endl;
}
