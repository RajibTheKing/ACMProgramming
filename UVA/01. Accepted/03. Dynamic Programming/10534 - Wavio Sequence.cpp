#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#include<vector>
using namespace std;
#define SZ 10100
#define inf 1<<30

int n; // the number of items in the sequence
int Sequence[SZ]; // the sequence of integers
int L[SZ]; // L[] as described in the algorithm
int I[SZ]; // I[] as described in the algorithm
int LisNlogK()
{
    int i;
    I[0] = -inf;


    for( i = 1; i <= n; i++)
        I[i] = inf;

    int LisLength = 0;



    for( i = 0; i < n; i++ )
    {
        int low, high, mid;
        low = 0;
        high = LisLength;
        while( low <= high )
        {
            mid = ( low + high ) / 2;
            if( I[mid] < Sequence[i] )
                low = mid + 1;
            else
                high = mid - 1;

        }

        I[low] = Sequence[i];
        L[i]=low;
        if( LisLength < low )
            LisLength = low;


    }
    return LisLength;
}



main()
{
    int ans, temp;
    vector<int> L_increasing, L_decreasing;
    while(cin>>n)
    {
        L_increasing.clear();
        L_decreasing.clear();
        for(int i = 0; i < n; i++)
            cin>>Sequence[i];
        ans=LisNlogK();
        for(int i=0;i<n;i++)
            L_increasing.push_back(L[i]);

        for(int i=0, k=n-1;i<k;i++, k--)
        {
            temp=Sequence[i];
            Sequence[i]=Sequence[k];
            Sequence[k]=temp;

        }
        ans=LisNlogK();
        for(int i=n-1;i>=0;i--)
            L_decreasing.push_back(L[i]);
        int Max_Sequence = -1;
        for(int i=0;i<n;i++)
            Max_Sequence = max(Max_Sequence, min(L_increasing[i], L_decreasing[i]));
        cout<<Max_Sequence*2-1<<endl;
    }
}
