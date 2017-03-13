#include<iostream>
#include<string>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<stdio.h>
using namespace std;
int sum;
void merg(int p, int r)
{

    if(p+1==r)
        sum+=p*r;
    int q;

    if(p<r)
    {
        q = ceil((p+r)/2);
        merg(p, q);
        merg(q+1, r);
    }
}
int main()
{
   int n;
   int i;
   while(cin>>n)
   {

        sum = 0;

        merg(1, n);

        cout<<sum<<endl;
   }

    return 0;
}
