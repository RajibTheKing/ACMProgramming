#include<iostream>
#include<string>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<stdio.h>

using namespace std;
int main()
{
    int n;
    cin>>n;
    int r, e, c;

    while(n--)
    {
        cin>>r>>e>>c;
        if((r+c)<e)
            printf("advertise\n");
        else if((r+c)==e)
            printf("does not matter\n");
        else
            printf("do not advertise\n");

    }

    return 0;
}
