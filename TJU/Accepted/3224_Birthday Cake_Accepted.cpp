#include<iostream.h>

int main()
{
    long long a[10000], b[10000], n, p;
    long long i, j;
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>a[i];
        cin>>b[i];
        p=a[i]*b[i];
        cout<<p-1<<"\n";
    }
    return 0;

}

