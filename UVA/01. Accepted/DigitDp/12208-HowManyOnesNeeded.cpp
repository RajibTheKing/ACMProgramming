#include <iostream>
#include <string>

#include <string.h>

using namespace std;

bool num1[64];
bool num2[64];
int blen1;
int blen2;
long long dp[64][64][2];


void makeBinary(long long num, bool numArray[], int &blen)
{
    bool arr[64];
    int indx=0;
    while(num)
    {
        if(num&1)
        {
            numArray[indx++] = 1;
        }
        else
        {
            numArray[indx++] = 0;
        }
        num = num>>1;
    }
    blen = indx;

}

void PrintBinary(string msg, long long hello)
{
    cout<<msg;
    while(hello)
    {
        if(hello&1)
        {
            cout<<"1";
        }
        else
        {
            cout<<"0";
        }
        hello = hello>>1;
    }
    cout<<endl;
}

long long countBinaryOne(int cur, int ones, bool flag, long long targetNum)
{
    //cout<<"Cur = "<<cur<<", ones = "<<ones<<", flag = "<<flag<<endl;

    if(cur<0) return ones;

    long long &ret = dp[cur][ones][flag];
    if(ret!=-1) return ret;

    ret = 0;

    int curDigit;

    if(targetNum&(1<<cur))
    {
        curDigit = 1;
    }
    else
    {
        curDigit = 0;
    }

    for(int i=0;i<=1;i++)
    {
        if(i<=curDigit || flag)
            ret += countBinaryOne(cur-1, ones+(i==1), flag || (i<curDigit), targetNum);
    }

    return ret;

}

int main()
{
    long long a, b, ans1,ans2;
    int kase = 0;

    while(cin>>a>>b)
    {
        if(a==0 && b==0) break;

        if(a-1>=0)
            makeBinary(a-1,num1,blen1);

        if(b>=0)
        makeBinary(b,num2,blen2);

        /*for(int i=0;i<blen1;i++)
        {
            cout<<num1[i]<<" ";
        }
        cout<<endl;

        for(int i=0;i<blen2;i++)
        {
            cout<<num2[i]<<" ";
        }
        cout<<endl;*/

        memset(dp, -1, sizeof(dp));
        ans1= countBinaryOne(blen2-1,0,false,b);


        memset(dp, -1, sizeof(dp));
        if(a-1>0)
            ans2= countBinaryOne(blen1-1,0,false,a-1);
        else
            ans2 = 0;


        //cout<<"ans1 = "<<ans1<<", ans2 = "<<ans2<<endl;
        cout<<"Case "<<++kase<<": ";

        cout<<ans1-ans2<<endl;




    }
    return 0;
}
