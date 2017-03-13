#include<iostream>
#include<vector>
#include<stdio.h>
#include<string>
#include<string.h>
#define sz 5000
using namespace std;

int W[sz], C[sz];
int dp[sz][sz];

int Recursion(int indx, int load)
{
    if(indx<0||load>3000) return 0;
    int &ret = dp[indx][load];
    if(ret!=-1) return ret;

    ret = 0;
    if(load<=C[indx])
        ret = max(ret, 1+ Recursion(indx-1, W[indx]+load));
    ret = max(ret, Recursion(indx-1, load));
    //cout<<"ret: "<<ret<<endl;
   return ret;
}
int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0) break;
        for(int i=0;i<n;i++)
            cin>>W[i]>>C[i];
       memset(dp, -1, sizeof(dp));

        cout<<Recursion(n-1, 0)<<endl;

    }

}
