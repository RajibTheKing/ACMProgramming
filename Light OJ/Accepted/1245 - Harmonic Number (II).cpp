#include<iostream>
#include<math.h>
using namespace std;

unsigned long long calculate(unsigned long long n)
{
    unsigned long long r, i, j, down, top,  s, temp;

    s = sqrt(n);
    r=0;
    for(i=1;i<=s;i++)
        r+=n/i;

    top = n;
    for(j=1;j<=i;j++)
    {
        down = n/(j+1);

        if(s>down)
            down=s;

        temp = top - down;

        r = r + temp*j;

        top = down;
    }

    return r;

}

int main()
{
    int T, kase=0;
    unsigned long long n, ans;
    cin>>T;
    while(T--)
    {
        cin>>n;
        ans = calculate(n);

        cout<<"Case "<<++kase<<": "<<ans<<endl;
       // cout<<ans<<endl;

    }
    return 0;
}
