#include<iostream.h>
#include<stdio.h>
#include<math.h>
int main()
{
    int n, k[100000];
    int a[100000], prime[100000];
    int i, j, c=0;
    for(i=0; i<100000; i++)
        a[i]=i;
    for(i=2;i<100000; i++)
    {
        if(a[i]==0)
            continue;
        else
        {

            prime[++c]=i;

            for(j=i+i; j<100000; j=j+i)
                a[j]=0;

        }
    }
    cin>>n;
    for(i=0; i<n; i++)
        cin>>k[i];
    for(i=0; i<n; i++)
        cout<<prime[k[i]]<<"\n";


    return 0;
}
