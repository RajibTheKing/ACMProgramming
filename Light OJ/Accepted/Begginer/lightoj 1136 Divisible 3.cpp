#include<iostream>
#include<string>
using namespace std;


int check(long long n)
{
    if((n*(n+1)/2)%3==0) return 1;
    return 0;
}

int main()
{

    int T, kase=0, account=0, n, money;
    cin>>T;
    long long diff, st,ed, res;
    while(T--)
    {
        cin>>st>>ed;
        diff=ed-st;
        if(diff%3==0)
            res = diff*2/3+check(ed);
        else if(diff%3==1)
            res = (diff-1)*2/3 + check(ed)+check(ed-1);
        else
            res = (diff-2)*2/3 + 2;
        cout<<"Case "<<++kase<<": "<<res<<endl;
    }
    return 0;
}
