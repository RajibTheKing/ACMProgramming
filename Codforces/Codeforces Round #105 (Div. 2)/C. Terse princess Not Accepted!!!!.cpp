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

using namespace std;
typedef long long LL;


int main()
{
    int R[300];
    int a, b, n;
    R[0]=300;

    cin>>n>>a>>b;

    if(a==0&&b==0)
    {
        R[0]=300;
        for(int i=1;i<n;i++)
            R[i]=R[i-1]-1;
        for(int i=0;i<n;i++)
            cout<<R[i]<<" ";
       // cout<<endl;
        goto end;
    }
    else if(a==n-1&&b==0)
    {
       cout<<"-1";
    }
    else
    {
        R[0]=2;
        R[1]=3;
        int sum = 5;

        int i, j;

        for(i=1,j=1;j<b;j++)
        {
            i++;
            R[i] = sum+1;
            sum+=R[i];
        }

        for(i=i+1,j=0;j<a;j++,i++)
        {
            R[i]=R[i-1]+1;
            sum+=R[i];
        }
        if(b==0)
            R[1]=1;

        for(i;i<n;i++)
            R[i]=R[i-1];
        for(int i=0;i<n;i++)
            cout<<R[i]<<" ";
        //cout<<endl;



    }
    end:
    cout<<endl;

    return 0;

}




