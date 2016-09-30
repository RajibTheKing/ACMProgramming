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
#define Max 5842

using namespace std;
typedef long long LL;
LL humble[6000];
int k, kount=0;
map<LL, bool> R;
int prime[]  = {2,3,5,7};

void rec(double t1, double t2, double t3, double t4)
{
    if(t1>31||t2>20||t3>14||t4>12) return;

    if(k>Max) return;
    LL num = pow(2, t1) * pow(3, t2) * pow(5, t3) * pow(7, t4);
    //cout<<num<<endl;
    if(num>2000000000) return;
    if(R[num]==false)
    {
        humble[++k]=num;
        R[num]=true;
    }
    else return;

    rec(t1+1, t2, t3, t4);
    rec(t1, t2+1, t3, t4);
    rec(t1, t2, t3+1, t4);
    rec(t1, t2, t3, t4+1);
    return;

}

int main()
{
    k=-1;
    R.clear();
    rec(0, 0, 0, 0);
    sort(&humble[0], &humble[5842]);
    int n;
    while(cin>>n)
    {
        if(n==0) break;
        int d1=0, d2=0;
        int temp = n;
        d2 = temp%10;
        temp/=10;

        if(temp)
            d1=temp%10;


        printf("The %d", n);
        if(d1==1&&(d2==1||d2==2||d2==3))
            printf("th");
        else if(d2==1)
            printf("st");
        else if(d2==2)
            printf("nd");
        else if(d2==3)
            printf("rd");
        else
            printf("th");
        printf(" humble number is %lld.\n", humble[n-1]);

    }

}
