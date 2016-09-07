#include<iostream>
#include<string.h>

using namespace std;

int dp[25];

int bottomUp()
{
    dp[0] = 1;

    dp[2] = 1;
    dp[4] = 2;
    for(int i=6;i<=20;i+=2)
    {
        dp[i]=0;
        for(int j=2;j<=i;j+=2)
        {
            dp[i]+=dp[i-j]*dp[j-2];
        }
    }
    /*for(int i=2;i<=20;i+=2)
    {
        cout<<dp[i]<<endl;
    }*/

}
int rec(int n)
{
    //cout<<"Here: "<<n<<endl;

    if(n<=0) return 1;
    if(n==2) return 1;
    if(n==4) return 2;

    int &ans = dp[n];
    if(ans!=-1) return ans;

    ans=0;

    for(int i=2;i<=n;i+=2)
    {
        ans= ans+ (rec(n-i)*rec(i-2));
    }

    return ans;


}
int main()
{
    bottomUp();

    int n;
    //memset(dp, -1, sizeof(dp));
    bool flag = false;
    while(cin>>n)
    {

        if(flag)
            cout<<endl;
        flag=true;
        //cout<<rec(n*2)<<endl;
        cout<<dp[n*2]<<endl;
    }

}
