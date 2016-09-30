
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <queue>

#define pi 3.1415926535897932384626433832795
#define INF 9999999
using namespace std;




int main()
{
    int n, k1, k2, p1, p2;
    int matrix[200][200];
    while(cin>>n&&n!=0)
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                cin>>matrix[i][j];
        k1=0;k2=0;
        for(int i=1;i<=n;i++)
        {
            int sum=0;
            for(int j=1;j<=n;j++)
                sum+=matrix[i][j];

            if(sum%2==1)
            {
                k1++;
                p1=i;
            }

        }

        for(int j=1;j<=n;j++)
        {
            int sum=0;
            for(int i=1;i<=n;i++)
                sum+=matrix[i][j];
            if(sum%2==1)
            {
                k2++;
                p2=j;
            }
        }
        if(k1==0&&k2==0)
            cout<<"OK"<<endl;
        else if(k1==1&&k2==1)
            cout<<"Change bit ("<<p1<<","<<p2<<")"<<endl;
        else
            cout<<"Corrupt"<<endl;


    }

    return 0;
}
