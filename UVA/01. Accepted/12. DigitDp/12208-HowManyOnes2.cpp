#include<iostream>
#include<algorithm>

using namespace std;

int max(int a,int b){
    if(a>b) return a;
    return b;
}

int getBinaryLen(long long num)
{
    int cnt=0;
    while(num)
    {
        cnt++;
        num/=2;
    }
    return cnt;
}

long long calculate(long long num)
{
    //cout<<"For: "<<num<<endl;

    int len = getBinaryLen(num);

    long long totalOnes = 0;

    for(int i=1;i<=len;i++)
    {
        int now = (num+1) / (1<<i);

        now*=(1<<(i-1));

        totalOnes = totalOnes + now;

        int alada = (num+1)%(1<<i);
        int rem = 0;

        rem = max(0,alada - (1<<(i-1)) );
        totalOnes+=rem;
        //cout<<"TotalOnes = "<<totalOnes<<endl;
    }
    return totalOnes;
}


int main()
{
    long long a, b, kase=0, ans1, ans2;
    while(cin>>a>>b)
    {
        if(a==0 && b==0)
            break;


        long long tempNum = b;
        ans2 = calculate(b);
        ans1 = calculate(a-1);
        cout<<"Case "<<++kase<<": ";
        cout<<ans2-ans1<<endl;

    }
}
