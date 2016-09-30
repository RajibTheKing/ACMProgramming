#include<iostream>
#include<string>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<stdio.h>
using namespace std;


struct node
{
    int x;
    int y;
    int h;
};

int main()
{
    int n;

    node a[505];
    int i, j;

    int ans1, ans2, ans3;
    int d;
    while(cin>>n)
    {
        for(i=0;i<n;i++)
        {
            cin>>a[i].x;
            cin>>a[i].y;
            a[i].h = i+1;
        }


        d = 0;
        ans3 = 0;

        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i==j) continue;

                d = (a[i].x-a[j].x)*(a[i].x-a[j].x) + (a[i].y-a[j].y)*(a[i].y-a[j].y);


                if(d>ans3)
                {
                    ans3=d;
                    ans1 = a[i].h;
                    ans2 = a[j].h;
                }

            }
        }

        if(ans1<ans2)
            printf("%d %d\n", ans1, ans2);
        else
            printf("%d %d\n", ans2, ans1);




    }

    return 0;
}
