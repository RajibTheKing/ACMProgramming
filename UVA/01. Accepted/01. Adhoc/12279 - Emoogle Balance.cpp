#include<iostream>
#include<map>
#include<math.h>
#include<cmath>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
using namespace std;
main()
{
    int N;
    int t1, t2, t, kase=0;
    while(cin>>N&&N)
    {
        t1=0;
        t2=0;
        for(int i=0;i<N;i++)
        {
            cin>>t;
            if(t) t1++;
            else t2++;
        }
        cout<<"Case "<<++kase<<": "<<t1-t2<<endl;

    }
}
