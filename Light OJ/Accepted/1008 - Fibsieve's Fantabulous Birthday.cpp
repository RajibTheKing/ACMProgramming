#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
long long x, y;

void find_in_even(long long s, long long n)
{
    long long k, l, m;
    l=s*s;
    m=l-n;

    if(m<=(s-1))
    {
        x=s;
        y=1+(l-n);
        return;
    }

    if(m>(s-1))
    {
        y=s;
        k=l-s+1;

        x=s-(k-n);
        return;
    }
}
void find_in_odd(long long s, long long n)
{
    long long k, l, m;
    l=s*s;
    m=l-n;

    if(m<=(s-1))
    {
        y=s;
        x=1+(l-n);
        return;
    }

    if(m>(s-1))
    {
        x=s;
        k=l-s+1;

        y=s-(k-n);

        return;
    }

}
int main()
{

    int t, kase=0;
    cin>>t;
    long long n;
    double temp;
    long long a, m, s , ans;
    while(t--)
    {
        cin>>n;
        temp = sqrt(n);

        s = ceil(temp);

        if(s%2==0)
            find_in_even(s, n);
        else
            find_in_odd(s, n);


        cout<<"Case "<<++kase<<": "<<x<<" "<<y<<endl;

    }

}
