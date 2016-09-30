//6 7
//2 1 3 4 0 6 5

#include<iostream>
#include<map>
#include<math.h>
#include<cmath>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
using namespace std;
#define SZ 1000
main()
{
    int N, B;
    int a[SZ];
    map<int, bool> M;
    while(cin>>N>>B)
    {
        if(N==0&&B==0) break;
        M.clear();

        for(int i=0;i<B;i++)
            cin>>a[i];
        for(int i=0;i<B;i++)
        {
            for(int j=0;j<B;j++)
            {
                int temp = abs(a[j]-a[i]);
                M[temp]=true;
            }
        }
        bool flag=true;
        for(int i=0;i<=N;i++)
        {
            if(M[i]==false)
            {
                flag=false;
                break;
            }
        }
        if(flag)
            cout<<"Y"<<endl;
        else
            cout<<"N"<<endl;
    }

}

