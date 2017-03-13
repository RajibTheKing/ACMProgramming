#include<stdio.h>
#include<math.h>
#include<string>
#include<string.h>
#include<map>
#include<algorithm>
#include<vector>

using namespace std;


main()
{
    int test, p1, p2;
    scanf("%d", &test);
    int time, kase = 0;
    while(test--)
    {
        time=0;
        scanf("%d %d", &p1, &p2);
        if(p1<p2)
            time+=(p2-p1)*4;
        else
            time+=(p1-p2)*4;

        time+=11;

        time+=(p1*4)+8;
        printf("Case %d: %d\n",++kase, time);

    }


}

