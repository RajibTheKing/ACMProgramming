#include<stdio.h>
#include<math.h>
#include<string>
#include<string.h>
#include<map>
#include<algorithm>
#include<vector>

using namespace std;

int  make_binary(int n)
{
    int count = 0;
    while(n)
    {
        if(n%2==1)
            count++;
        n=n/2;

    }
    return count;

}
main()
{
    int test, flag;
    scanf("%d", &test);


    for(int i=0;i<test; i++)
    {
        int n;
        scanf("%d", &n);
        flag = make_binary(n);

        if(flag%2==1)
            printf("Case %d: odd\n", i+1);
        else
            printf("Case %d: even\n", i+1);

    }

}
