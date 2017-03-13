#include<iostream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<cctype>
#include<set>
#include<bitset>
#include<algorithm>
#include<list>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

typedef long long LL;
using namespace std;

#define sz 50001
int prime[5000];
bool flag[sz+100];

int sieve(void)
{
    int i, j, k=-1, r;
    for(i=3;i<=sz;i+=2)
        flag[i]=true;
    flag[2]=true;
    prime[++k]=2;
    for(i=3;i<sz;i+=2)
    {
        if(flag[i])
        {
            prime[++k]=i;
            if(sz/i>=i)
            {
                r=i*2;
                for(j=i*i;j<sz;j+=r)
                    flag[j]=false;
            }
        }
        if(prime[k]>800) break;
    }

    //for(int i=0;i<100;i++)
        //cout<<prime[i]<<endl;

    //cout<<"Last Prime: "<<k<<" th = "<<prime[k]<<endl;
    return k;

}

double A[3000010];

void calculate()
{
    A[0]= 0;
    A[1]=log(1);

    for(int i=2;i<=3000000;i++)
        A[i]=A[i-1]+log(i);
    //for(int i=1;i<10;i++)
        //cout<<A[i]<<endl;
}
int factors_in_factorial(int N, int P)
{
    int sum=0;
    while(N)
    {
        sum+=N/P;
        N/=P;
    }
    return sum;
}
int Trailingzero_Base_B(int N, int B)
{
    int i, ans , freq, power;
    ans = 999999999;
    for(i=0;prime[i]<=B;i++)
    {
        if(B%prime[i]==0)
        {
            freq=0;
            while(B%prime[i]==0)
            {
                freq++;
                B/=prime[i];
            }
            power = factors_in_factorial(N, prime[i]);
            ans = min(ans, power/freq);
        }
    }
    return ans;
}
int main()
{
    calculate();
    //cout<<"complete"<<endl;

    int lim = sieve();
    int N, B;
    double temp, temp2;

    while(cin>>N>>B)
    {

        temp = A[N];
        temp = temp/log(B);
        temp+=1.0;
        temp=floor(temp);
        temp2=Trailingzero_Base_B( N, B);

        printf("%0.lf %0.lf\n",temp2, temp);

    }
}



