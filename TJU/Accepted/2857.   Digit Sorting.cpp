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


int main()
{
    int a[100];
    int N;

    while(cin>>N)
    {
        char c[50];
        if(N==0) break;

        for(int i=0;i<N;i++)
        {
            cin>>a[i];
            sprintf(c, "%d", a[i]);
            sort(c, c+strlen(c));
            a[i]=atoi(c);
        }


        sort(a, a+N);
        cout<<a[N-1]<<endl;

    }
    return 0;

}

