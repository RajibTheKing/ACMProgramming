#include<iostream>
using namespace std;
int main()
{
    int T, kase =0;
    int p, l, res;
    cin>>T;
    while(T--)
    {
        cin>>p>>l;


        res = 0;
        res+=19;

        if(p>l)
            res+=(p-l) * 4;
        else
            res+=(l-p) * 4;

        res+=p*4;

        printf("Case %d: %d\n", ++kase, res);


    }
}
